#include <iostream>

#include <functional>

#include <random>

#include <vector>

#include <algorithm>

#include <chrono>

using namespace std;

#include <fstream>

#include <string>

void generateFile(int, string inputFileName = "io.cpp", string outputFileName = "io.txt");

void showFile(string inputFileName = "io.txt");

int randomNumber(int, int);

void vectorData(vector<int> &, int, int, int);

void showVector(vector<int> &);

short int breadManager(int, int, vector<short int> &, int, int);

vector<int> breadSort(vector<int> &, int);