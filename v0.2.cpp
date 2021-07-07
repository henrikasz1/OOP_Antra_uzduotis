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

int main ()
{

  srand(time(0));
  vector<data> B;//vektorius, kuriame bus kiekvieno mokinio duomenys
  //-----
  char check; //elementas, kuris tikrina, ar norima ivesti dar viena mokini
  char choice; // elementas, kuris tikrina, kokiu budu ivesti namu darbu rezultatus
  char read; //elementas, kuris tikrina, ar duomenys bus nuskaityti is failo, ar ivesti per console

  int n=0;//vektoriaus dydis

  //nuskaitymas
  cout << "Ar norite ivesti duomenis, ar, kad juos nuskaitytu is failo? \n Ivesti - spauskite 1 \n Nuskaityti is failo - iveskite bet koki kita elementa \n";
  cin >> read;
  if (read=='1')
  {
        do //jeigu 1, ciklas kartojamas, jeigu ivedamas kitas skaicius, ciklas baigiasi, jeigu cin.fail(), ciklas taip pat baigiasi
        {
          B.push_back(data());
          cout << "Iveskite mokinio varda\n";
          cin >> B[n].name;
          for (int p=0; p<B[n].name.length(); p++)
          {
            while(!isalpha(B[n].name[p]))
            {
                cout << "Ivedete netinkama reiksme, bandykite dar karta \n";
                cin.clear();
                cin >> B[n].name;
            }
          }
          cout << "Iveskite mokinio pavarde \n";
          cin >> B[n].lastName;
          for (int b=0; b<B[n].lastName.length(); b++)
          {
            while(!isalpha(B[n].lastName[b]))
            {
                cout << "Ivedete netinkama reiksme, bandykite dar karta \n";
                cin.clear();
                cin >> B[n].lastName;
            }
          }

          //-----------------
          cout << "Ar norite, kad pazymius: \nSugeneruotu automatiskai? - iveskite bet koki kita elementa \n Suvestumete patys? - iveskite 1\n";
          cin >> choice;
          int more=1;
          int input; //input'as vektoriui
          if (choice=='1')
          {
            while(more==1)
            {
              cout << "Iveskite pazymi \n";
              cin >> input;
              B[n].A.push_back(input);
              while (input<0 || input>10 ||cin.fail())
              {
                B[n].A.pop_back();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ivedete netinkama reiksme \n";
                cin >> input;
                B[n].A.push_back(input);
              }
              cout << "Ar norite ivesti dar viena pazymi?\n Jei taip - spauskite 1 \n Jei ne - iveskite bet koki kita elementa \n";
              cin >> more;
            }
          }
          else
          {
              int random=rand()%10+1;
              for (int j=0; j<random; j++)
              {
                B[n].A.push_back(rand()%10+1);
              }
          }

          //-------------
          cout << "Iveskite mokinio egzamino rezultata \n";
          cin >> B[n].egz;
          while(cin.fail() || B[n].egz<0 || B[n].egz>10)
          {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Egzamino rezultatas gali buti sudarytas tik is skaciu, bandykite dar karta \n";
            cin >> B[n].egz;
          }
          n++;
          cout << "Ar norite ivesti dar vieno mokinio duomenis? \n Jei taip, spauskite 1 \n Jei ne, iveskite bet koki kita elementa \n";
          cin >> check;
        }while(check=='1');
 }
 else
 {
    ifstream in ("kursiokai.txt");
    int nd;//kintamasis, kuriuo nuskaitysiu visus skaicius
    string line; //kintamasis, kuriuo nuskaitysiu visa eilute
        while (getline(in, line))//kol galima paimti eilute, tol nuskaitines
        {
          istringstream enter(line);//kadangi getline() paima duomenis stringo formatu, naudoju istringstream, kad extractint elementus
          B.push_back(data());
          enter >> B[n].name;
          enter >> B[n].lastName;
          while(enter)
          {
            enter >> nd;
            B[n].A.push_back(nd);
          }
          B[n].egz=B[n].A.back();
          B[n].A.pop_back();//istrinu paskutini, nes tai yra egzamino rezultatas
          n++;
        }
    in.close();
 }
    //kreipiasi i funkcijas ir apskaiciuoja mediana/vidurki
    for (int e=0; e<n; e++)
    {
      B[e].median=0.4*median(B[e].A)+0.6*B[e].egz;
    }
    for (int e=0; e<n; e++)
    {
      B[e].average=0.4*average(B[e].A)+0.6*B[e].egz;
    }
    output (n, B);//isvedimo funkcija
  return 0;
}
double median (vector<int> A)
{
  int a, b;//laikinieji kintamieji medianos skaiciavimui
  sort(A.begin(), A.end());
  if (A.size()%2==0)
  {
    a=A.size()/2;
    b=A.size()/2-1;
    return (A[a]+A[b])*1.0/2;
  }
  else
  {
    a=A.size()/2;
    return A[a];
  }
}
double average (vector<int> A)
{
  int total=0;
  for(int i=0; i<A.size(); i++)
  {
    total+=A[i];
  }
  return total*1.0/A.size();
}
void output (int n, vector<data> B)
{
      system("cls");//isnaikina teksta, kuris nereikalingas ir trukdo lenteles skaitymui
      //surikiuoju duomenis pagal varda
      for (int i=0; i<n-1; i++)
          for (int j=i+1; j<n; j++)
              if (B[i].name>B[j].name || (B[i].name==B[j].name && B[i].lastName>B[j].lastName))
              {
                swap(B[i], B[j]);
              }
      //randa ilgiausia varda ir pavarde, tai pades graziai islygiuoti teksta
      int largestName=0;
      int largestLastName=0;
      for (int i=0; i<n; i++)
      {
        if (B[i].name.size()>largestName) largestName=B[i].name.size();
      }
      for (int i=0; i<n; i++)
      {
        if (B[i].lastName.size()>largestLastName) largestLastName=B[i].name.size();
      }
      //isvedimas
      cout << "-------------------------------------------------------------------" << endl;
      cout << left << setw(largestName+1) << "Vardas";
      cout << left << setw(largestLastName+3) << "Pavarde";
      cout << left << setw(16) << "Galutinis(Med.)";
      cout << "Galutinis(Vid.)\n";
      cout << "-------------------------------------------------------------------" << endl;
      for (int i=0; i<n; i++)
      {
        cout << left << setw (largestName+1) << B[i].name;
        cout << left << setw (largestLastName+3) << B[i].lastName;
        cout << left << setw (16) << fixed<<setprecision(2) << B[i].median;
        cout << fixed << setprecision(2) << B[i].average;
        cout<<endl;
      }

}
