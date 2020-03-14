#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <exception>
#include <chrono>
#include <cctype> //skirtas patikrinti, ar tinkamai suvestas vardas/pavarde
#include "struct.h"

using namespace std;
double median (vector<int> &A);
double average (vector<int> &A);
void output (int n, vector <data> &B);
void generateFile(int kiekis, int nddydis, string &a);
int displayHelper (int number);
void readFile(list<data> &M, string name, int numOfStudents, int nddydis);
void distributeFile(int numOfStudents, list<data> &M);

#endif// FUNCTIONS_H
