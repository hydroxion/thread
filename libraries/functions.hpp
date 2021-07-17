#include <iostream>

#include <functional>

#include <random>

#include <vector>

#include <algorithm>

#include <chrono>

#include <fstream>

#include <string>

using namespace std;

void generateFile(int, string inputFileName = "io.cpp", string outputFileName = "io.txt");

void copyFile(int, string inputFileName = "io.txt", string outputFileName = "copy/io.txt");

void showFile(string inputFileName = "io.txt");

int randomNumber(int, int);

void vectorData(vector<int> &, int, int, int);

void showVector(vector<int> &);

short int breadManager(int, int, vector<short int> &, int, int);

vector<int> breadSort(vector<int> &, int);