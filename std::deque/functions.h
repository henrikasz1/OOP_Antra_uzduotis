#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <exception>
#include <chrono>
#include <cctype> //skirtas patikrinti, ar tinkamai suvestas vardas/pavarde
#include "struct.h"

using namespace std;
double median (deque<int> &A);
double average (deque<int> &A);
void output (int n, deque <data> &B);
void generateFile(int kiekis, int nddydis, string &a);
int displayHelper (int number);
void readFile(deque<data> &M, string name, int &k, int nddydis);
void distributeFile(int numOfStudents, int k, deque<data> &M);

#endif// FUNCTIONS_H
