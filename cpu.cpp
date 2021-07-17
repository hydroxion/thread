#include "libraries/functions.hpp"

int main(int argc, char *argv[], char **envp)
{
	// Clock start
	auto execution_start = chrono::high_resolution_clock::now();

	// Generate the vector of random numbers
	vector<int> numbers;

	vectorData(numbers, 10000, 0, 10000);

	// Show vector of random numbers
	showVector(numbers);

	// Sort the vector of random numbers
	vector<int> sorted = breadSort(numbers, numbers.size());

	// Show the vector of random numbers sorted
	showVector(sorted);

	// Clock end
	auto execution_end = chrono::high_resolution_clock::now();

	// Clock calcule
	cout << chrono::duration_cast<chrono::microseconds>(execution_end - execution_start).count() << " Microseconds" << endl;

	return 0;
}