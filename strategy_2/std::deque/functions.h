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
void output (int n, deque <student> &B);
void generateFile(int kiekis, int nddydis, string &a);
int displayHelper (int number);
void readFile(deque<student> &M, string name);
void distributeFile(int numOfStudents, deque<student> &M, deque<student> &kvaili);

#endif// FUNCTIONS_H
