#include "libraries/functionsThread.hpp"

int main(int argc, char *argv[], char **envp)
{
	// Show the amount of threads available
	cout << "Hardware threads " << thread::hardware_concurrency() << endl;

	// Clock start
	auto execution_start = chrono::high_resolution_clock::now();

	// Generate the vector of random numbers
	vector<int> numbers;

	thread thread1(Thread::vectorData, ref(numbers), 10000, 0, 10000);

	thread1.join();

	// Show vector of random numbers
	thread thread2(Thread::showVector, ref(numbers));

	thread2.join();

	// Sort the vector of random numbers and show
	auto future = async(launch::async, bind(Thread::breadSort, numbers, numbers.size()));

	vector<int> sorted = future.get();

	// Show sorted file
	thread thread4(Thread::showVector, ref(sorted));

	thread4.join();

	// Clock end
	auto execution_end = chrono::high_resolution_clock::now();

	// Clock calcule
	cout << chrono::duration_cast<chrono::microseconds>(execution_end - execution_start).count() << " Microseconds" << endl;

	return 0;
}