#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

using namespace std;
struct student{
  string name;//vardas
  string lastName;//pavarde
  int egz;//egzamino rezultatai
  double median;//naudojamas medianos isvedimui
  double average;//naudojamas vidurkio isvedimui
  int m=0; //namu darbu rezultatu kiekis
  vector<int> A; //vektorius, kuriame bus saugojami namu darbu rezultatai
};//struktura

#endif // STRUCT_H_INCLUDED
