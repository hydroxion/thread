#include "library/functions.hpp"

int main(int argc, char *argv[], char **envp)
{
    auto execution_start = chrono::high_resolution_clock::now();

    // One milion generates a 1 GB file
    generateFile(1000000);

    // Copy file
    copyFile(100);

    // Show the generated file
    showFile();

    auto execution_end = chrono::high_resolution_clock::now();

    cout << chrono::duration_cast<chrono::microseconds>(execution_end - execution_start).count() << " Seconds" << endl;

    return 0;
}