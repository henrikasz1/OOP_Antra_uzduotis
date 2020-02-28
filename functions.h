#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

struct data{
  string name;//vardas
  string lastName;//pavarde
  int egz;//egzamino rezultatai
  double median;//naudojamas medianos isvedimui
  double average;//naudojamas vidurkio isvedimui
  int m=0; //namu darbu rezultatu kiekis
  vector<int> A; //vektorius, kuriame bus saugojami namu darbu rezultatai
};//struktura

double median (vector<int> A);
double average (vector<int> A);
void output (int n, vector<data> B);

#endif// FUNCTIONS_H
