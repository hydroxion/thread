#include "libraries/functions.hpp"

int main(int argc, char *argv[], char **envp)
{
    // Clock start
    auto execution_start = chrono::high_resolution_clock::now();

    // One milion generates a 1 GB file
    generateFile(1000000);

    // Copy file
    copyFile(100);

    // Show the generated file
    showFile();

    // Clock end
    auto execution_end = chrono::high_resolution_clock::now();

    // Clock calcule
    cout << chrono::duration_cast<chrono::microseconds>(execution_end - execution_start).count() << " Microseconds" << endl;

    return 0;
}