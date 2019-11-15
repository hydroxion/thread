#include "library/functions.hpp"

int main(int argc, char *argv[], char **envp)
{
    auto execution_start = chrono::high_resolution_clock::now();

    vector<int> numbers;

    vectorData(numbers, 50000, 1000, 10000);

    vector<int> sorted = breadSort(numbers, numbers.size());

    auto execution_end = chrono::high_resolution_clock::now();

    cout << chrono::duration_cast<chrono::microseconds>(execution_end - execution_start).count() << " Seconds" << endl;

    return 0;
}