#include "functionsThread.hpp"

#ifndef FUNCTIONS_THREAD

#define FUNCTIONS_THREAD

// Mutexes
mutex mutexVectorData;

// Conditions
condition_variable conditionVectorData;

#endif

void Thread::generateFile(int repeat, string inputFileName, string outputFileName)
{
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open())
    {
        cerr << "Input file not found" << endl;

        exit(1);
    }

    ofstream outputFile(outputFileName);

    if (!inputFile.is_open())
    {
        cerr << "Was not possible to create the output file" << endl;

        exit(1);
    }

    int counter = 0;

    string line;

    while (counter < repeat)
    {

        while (getline(inputFile, line))
        {
            // cout << line << endl;

            outputFile << line << endl;
        }

        inputFile.clear();

        inputFile.seekg(0, ios::beg);

        counter++;
    }

    inputFile.close();

    outputFile.close();
}

void Thread::copyFile(int repeat, string inputFileName, string outputFileName)
{
    ifstream inputFile(inputFileName, ios::binary);

    if (!inputFile.is_open())
    {
        cerr << "Input file not found" << endl;

        exit(1);
    }

    int counter = 0;

    while (counter < repeat)
    {
        string outputFileNameCache = outputFileName;

        int index = outputFileNameCache.find_last_of("/");

        outputFileNameCache.insert(index + 1, to_string(counter));

        ofstream outputFile(outputFileNameCache, ios::binary);

        outputFile << inputFile.rdbuf();

        inputFile.clear();

        inputFile.seekg(0, ios::beg);

        counter++;
    }
}

void Thread::showFile(string inputFileName)
{
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open())
    {
        cerr << "Input file not found" << endl;

        exit(1);
    }

    string line;

    while (getline(inputFile, line))
        cout << line << endl;
}

int Thread::randomNumber(int start, int end)
{
    auto rand = bind(uniform_int_distribution<int>{start, end},
                     default_random_engine{random_device()()});

    return rand();
}

void Thread::vectorData(vector<int> &numbers, int size, int start, int end)
{
    int counter = 0;

    while (counter < size)
    {
        unique_lock<mutex> locker(mutexVectorData);

        numbers.push_back(randomNumber(start, end));

        locker.unlock();

        conditionVectorData.notify_one();

        counter++;
    }
}

void Thread::showVector(vector<int> &numbers)
{
    cout << "Numbers [ ";

    int counter = 0;

    while (counter < numbers.size())
    {
        unique_lock<mutex> locker(mutexVectorData);
        
        conditionVectorData.wait(locker, [&]() { return !numbers.empty(); });

        cout << numbers[counter] << " ";

        locker.unlock();

        counter++;
    }

    cout << "]" << endl;
}

short int Thread::breadManager(int counter1, int counter2, vector<short int> &breads, int max, int value)
{
    if (value == 0 || value == 1)
        breads[counter1 * max + counter2] = value;

    return breads[counter1 * max + counter2];
}

vector<int> Thread::breadSort(vector<int> &numbers, int size)
{
    // Get the max element
    int max = *max_element(numbers.begin(), numbers.end());

    // Create the breads (exponential)
    vector<short int> breads(max * size);

    // Initialize the breads
    fill(breads.begin(), breads.end(), 0);

    // Mark the breads
    for (int counter_size = 0; counter_size < size; counter_size++)
        for (int counter_element = 0; counter_element < numbers[counter_size]; counter_element++)
            breadManager(counter_size, counter_element, breads, max, 1);

    for (int counter_max = 0; counter_max < max; counter_max++)
    {
        // Count the breads
        int total = 0;

        for (int counter_size = 0; counter_size < size; counter_size++)
        {
            total += breadManager(counter_size, counter_max, breads, max, -1);

            breadManager(counter_size, counter_max, breads, max, 0);
        }

        for (int counter_numbers = size - total; counter_numbers < size; counter_numbers++)
            breadManager(counter_numbers, counter_max, breads, max, 1);
    }

    // Get sorted values
    vector<int> sorted(size);

    for (int counter_size = 0; counter_size < size; counter_size++)
    {
        int counter_max = 0;

        for (; counter_max < max && breadManager(counter_size, counter_max, breads, max, -1); counter_max++)
            ;

        sorted[counter_size] = counter_max;
    }

    return sorted;
}