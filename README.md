# Thread

CPU and I/O benchmark.

## About

Benchmark between I/O and CPU with and without parallel computing. Read the [relatory](./relatory) see the results.

## Built with

- [C++](https://en.cppreference.com/w/)
- [Valgrind](https://valgrind.org/)

## Installation

Use the package manager APT to install general dependencies.

```sh
apt install build-essential g++
```

## Usage

Compile the CPU example.

```sh
g++ cpu.cpp libraries/functions.cpp -o cpu.bin -std=c++17 -O3 -g && ./cpu.bin
```

Compile the CPU example using threads.

```sh
g++ cpuThread.cpp libraries/functionsThread.cpp -pthread -o cpuThread.bin -std=c++17 -O3 -g && ./cpuThread.bin
```

Compile the I/P example.

```sh
g++ io.cpp libraries/functions.cpp -o io.bin -std=c++17 -O3 -g && ./io.bin
```

Compile the I/O example using threads.

```sh
g++ ioThread.cpp libraries/functionsThread.cpp -pthread -o ioThread.bin -std=c++17 -O3 -g && ./ioThread.bin
```

## Documentation

Use the package manager APT to install Valgrind.

```sh
apt install valgrind
```

Create a dynamic analysis of the CPU and I/O examples available:

```sh
valgrind --tool=callgrind ./cpu.bin # Change the binary name
```

Valgrind generates a _calgrind.out_ file that can be interpreted by tools like [Gprof 2 Dot](https://github.com/jrfonseca/gprof2dot) (`gprof2dot -f callgrind callgrind.out.* | dot -Tsvg -o output.svg` and then convert from SVG to PNG) or [kcache Grind](http://kcachegrind.sourceforge.net/html/Home.html).

> These tools are not demonstrated here because of Python dependencies and as system dependencies, aside from converting the image file, which you can use [Ink Scape](https://inkscape.org/) (`inkscape -z -e output.png input.svg`). More [tools](https://stackoverflow.com/questions/375913/how-can-i-profile-c-code-running-on-linux?rq=1)

Use the script `./clean.sh` to clean the assets generated by the benchmarks.

## Contributing

Pull requests are welcome. Please, consider the following.

1. Make sure you code have quality, a.k.a standards
2. Make sure your code is secure
3. Make sure your code has no performance issues
4. Make sure your code is documented, if necessary
5. Describe the changes that were done

> No issue or PR template required, but be informative

## License

[MIT](./LICENSE.md)
