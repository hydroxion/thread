### 🧠 Doomsday Clock

---

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/81542b5583a84f89857c7a18fdb5b5f2)](https://www.codacy.com/manual/Sphinxs/Doomsday-clock?utm_source=github.com&utm_medium=referral&utm_content=Sphinxs/Doomsday-clock&utm_campaign=Badge_Grade) [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com) ![GitHub last commit](https://img.shields.io/github/last-commit/sphinxs/Doomsday-clock)

---

Concurrency [CPU](https://stackoverflow.com/questions/868568/what-do-the-terms-cpu-bound-and-i-o-bound-mean) bound and [I/O](https://stackoverflow.com/questions/868568/what-do-the-terms-cpu-bound-and-i-o-bound-mean) bound tests in C++ using threads.

#### Setup

<details>
<summary>G++</summary>

Install the G++ compiler:

```sh
apt install build-essential g++
```

</details>

#### Run

<details>
<summary>CPU</summary>

Compile the CPU example:

```sh
g++ cpu.cpp libraries/functions.cpp -o cpu.bin -std=c++17 -O3 && ./cpu.bin
```

Compile the CPU thread example:

```sh
g++ cpuThread.cpp libraries/functionsThread.cpp -pthread -o cpuThread.bin -std=c++17 -O3 && ./cpuThread.bin
```

</details>

<details>
<summary>I/O</summary>

Compile the I/O example:

```sh
g++ io.cpp libraries/functions.cpp -o io.bin -std=c++17 -O3 && ./io.bin
```

Compile the I/O thread example:

```sh
g++ ioThread.cpp libraries/functionsThread.cpp -pthread -o ioThread.bin -std=c++17 -O3 && ./ioThread.bin
```

</details>

#### Relatory

<details>
<summary>Valgrind</summary>

Install the Valgrind:

```sh
apt install valgrind
```

And execute using some binary file as input:

```sh
valgrind --tool=callgrind ./cpu.bin # io.bin
```

The Valgrind will generate a _calgrind.out_ file that can be interpreted by tools like [Gprof 2 Dot](https://github.com/jrfonseca/gprof2dot) (`gprof2dot -f callgrind callgrind.out.* | dot -Tsvg -o output.svg` and then convert from SVG to PNG) or [kcache Grind](http://kcachegrind.sourceforge.net/html/Home.html)

> These two tools are not demonstrated here in both cases: as Python dependencies and as System dependencies, its necessary that you install by yourself

More tools [here](https://stackoverflow.com/questions/375913/how-can-i-profile-c-code-running-on-linux?rq=1)

</details>

<details>
<summary>Google Chrome Tracing</summary>

Its possible to generate a relatory by using some clock time like the Chrono C++ libraries, and format a JSON file that contains the time executions in miliseconds to show in the [Google Chrome Tracing](chrome://tracing/) native tool.

More about [here](https://www.youtube.com/watch?v=xlAH4dbMVnU).

</details>

#### Debug

<details>
<summary>GDB</summary>

```sh
gdb *.bin  # Load executable
```

```sh
run  # Execute the executable
```

```sh
backtrace  # Summary how the executable is running
```

```sh
kill  # Stop the executable
```

</details>

<details>
<summary>Files</summary>

To debug the generated file, two options are good to large files:

1. [Glogg](https://glogg.bonnefon.org/)

2. [Less](https://pt.wikipedia.org/wiki/Less)

</details>

### References

<details>
<summary>Bread (Gravity) Sort</summary>

[Gravity Sort (Bead Sort) Explained](https://www.youtube.com/watch?v=MneHbUXyKHg)

[Wiki Bread Sort](https://en.wikipedia.org/wiki/Bead_sort)

[Sorts](https://youtu.be/S0RtR2Yllzk?t=206)

[Bead Sort - A Natural Sorting Algorithm](https://www.geeksforgeeks.org/bead-sort-natural-sorting-algorithm/)

[Bead sort](https://rosettacode.org/wiki/Sorting_algorithms/Bead_sort)

[Bead Sort Algorithm](https://discourse.opengenus.org/t/bead-sort-algorithm/121)

[What is the fastest sorting algorithm](https://www.quora.com/What-is-the-fastest-sorting-algorithm)

</details>

<details>
<summary>C++</summary>

[Modern CPP features](https://github.com/AnthonyCalandra/modern-cpp-features)

[CPP Cheatsheet](https://github.com/mortennobel/cpp-cheatsheet)

</details>

<details>
<summary>Concurrency</summary>

[Concurrent Programming with C++ 11](https://www.youtube.com/playlist?list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M)

[Programming Concurrency In C++ - Part One](https://www.c-sharpcorner.com/article/programming-concurrency-in-cpp-part-1/)

[Programming Concurrency In C++ - Part Two](https://www.c-sharpcorner.com/article/programming-concurrency-in-cpp-part-2/)

[C++ Multithreading](https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm)

[Threads in C++](https://www.youtube.com/watch?v=wXBcwHwIt_I)

[Function Pointers in C++](https://www.youtube.com/watch?v=p4sDgQ-jao4)

</details>

<details>
<summary>Cuda</summary>

[GPU Accelerated Computing with C and C++](https://developer.nvidia.com/how-to-cuda-c-cpp)

[CUDA C/C++ Basics](https://www.nvidia.com/docs/IO/116711/sc11-cuda-c-basics.pdf)

</details>
