### 🧠 Doomsday Clock

---

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/81542b5583a84f89857c7a18fdb5b5f2)](https://www.codacy.com/manual/Sphinxs/Doomsday-clock?utm_source=github.com&utm_medium=referral&utm_content=Sphinxs/Doomsday-clock&utm_campaign=Badge_Grade) [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com) ![GitHub last commit](https://img.shields.io/github/last-commit/sphinxs/Doomsday-clock)

---

Concurrency CPU and I/O tests in C++ using threads.

#### Setup

<details>
<summary>G++</summary>

Install the G++ compiler:

`apt install build-essential g++`

</details>

#### Run

<details>
<summary>CPU</summary>

Compile the CPU example:

`g++ cpu.cpp library/functions.cpp -o cpu.bin -std=c++17 && ./cpu.bin`

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

### References

<details>
<summary>Bread (Gravity) Sort</summary>

[Gravity Sort (Bead Sort) Explained](https://www.youtube.com/watch?v=MneHbUXyKHg)

[Wiki Bread Sort](https://en.wikipedia.org/wiki/Bead_sort)

[Sorts](https://youtu.be/S0RtR2Yllzk?t=206)

[Bead Sort - A Natural Sorting Algorithm](https://www.geeksforgeeks.org/bead-sort-natural-sorting-algorithm/)

[Bead sort](https://rosettacode.org/wiki/Sorting_algorithms/Bead_sort)

[Bead Sort Algorithm](https://discourse.opengenus.org/t/bead-sort-algorithm/121)

</details>

<details>
<summary>C++</summary>

[Modern CPP features](https://github.com/AnthonyCalandra/modern-cpp-features)

[CPP Cheatsheet](https://github.com/mortennobel/cpp-cheatsheet)

</details>