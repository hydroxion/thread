#include "libraries/functionsThread.hpp"

int main(int argc, char *argv[], char **envp)
{
    // Show the amount of threads available
    cout << "Hardware threads " << thread::hardware_concurrency() << endl;

    // Clock start
    auto execution_start = chrono::high_resolution_clock::now();

    // Generate file
    thread thread1([]() { Thread::generateFile(1000); });

    thread1.join();

    // Copy file
    thread thread2([]() { Thread::copyFile(1000); });

    thread2.join();

    // Show the generated file
    thread thread3([]() { Thread::showFile(); });

    thread3.join();

    // Clock end
    auto execution_end = chrono::high_resolution_clock::now();

    // Clock calcule
    cout << chrono::duration_cast<chrono::microseconds>(execution_end - execution_start).count() << " Microseconds" << endl;

    return 0;
}