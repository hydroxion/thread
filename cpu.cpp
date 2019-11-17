#include "libraries/functions.hpp"

int main(int argc, char *argv[], char **envp)
{
    auto execution_start = chrono::high_resolution_clock::now();

    // Generate the vector of random numbers
    vector<int> numbers;

    vectorData(numbers, 5, 1000, 10000);

    // Show vector of random numbers
    showVector(numbers);

    // Sort the vector of random numbers
    vector<int> sorted = breadSort(numbers, numbers.size());

    // Show the vector of random numbers sorted
    showVector(sorted);

    auto execution_end = chrono::high_resolution_clock::now();

    cout << chrono::duration_cast<chrono::microseconds>(execution_end - execution_start).count() << " Seconds" << endl;

    return 0;
}