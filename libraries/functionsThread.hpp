#include <iostream>

#include <functional>

#include <random>

#include <vector>

#include <algorithm>

#include <chrono>

#include <fstream>

#include <string>

#include <mutex>

#include <condition_variable>

#include <thread>

#include <future>

using namespace std;

namespace Thread
{
void generateFile(int, string, string);

void copyFile(int, string, string);

void showFile(string);

int randomNumber(int, int);

void vectorData(vector<int> &, int, int, int);

void showVector(vector<int> &);

short int breadManager(int, int, vector<short int> &, int, int);

vector<int> breadSort(vector<int> &, int);
}