#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double median (vector<int> A);
double average (vector<int> A);
//void output (int n, data &B);

struct data{
  string name;//vardas
  string lastName;//pavarde
  int egz;//egzamino rezultatai
  double total;//naudojamas vidurkio isvedimui
  int m=0; //namu darbu rezultatu kiekis
  vector<int> A; //vektorius, kuriame bus saugojami namu darbu rezultatai
};//struktura
int main ()
{
  vector<data> B;//vektorius, kuriame bus kiekvieno mokinio duomenys
  //-----
  int check; //elementas, kuris tikrina, ar norima ivesti dar viena mokini
  int choice, cchoice;
  int n=0;//vektoriaus dydis

  //uzduotys before v0.2
  //keiciu B[n] i vektoriu B
  //sutvarkyti patikrinimus!!!!!!


  do //jeigu 1, ciklas kartojamas, jeigu ivedamas kitas skaicius, ciklas baigiasi, jeigu cin.fail(), ciklas taip pat baigiasi
  {
    B.push_back(data());
    cout << "Iveskite mokinio varda\n";
    cin >> B[n].name;
    for (int p=0; p<B[n].name.length(); p++)
    {
      while((B[n].name[p]<'A'|| B[n].name[p]>'Z')&&(B[n].name[p]<'a'||B[n].name[p]>'z'))
      {
          cout << "Ivedete netinkama reiksme, bandykite dar karta \n";
          cin >> B[n].name;
      }
    }
    cout << "Iveskite mokinio pavarde \n";
    cin >> B[n].lastName;
    for (int b=0; b<B[n].lastName.length(); b++)
    {
      while((B[n].lastName[b]<'A'|| B[n].lastName[b]>'Z')&&(B[n].lastName[b]<'a'||B[n].lastName[b]>'z'))
      {
          cout << "Ivedete netinkama reiksme, bandykite dar karta \n";
          cin >> B[n].lastName;
      }
    }

    //-----------------
    cout << "Ar norite, kad pazymius: \nSugeneruotu automatiskai? - iveskite bet kokia kita reiksme \n Suvestumete patys? - iveskite 1\n";
    cin >> choice;
    int more=1;
    int input; //input'as vektoriui
    if (choice==1)
    {
      while(more==1)
      {
        cout << "Iveskite pazymi \n";
        cin >> input;
        B[n].A.push_back(input);                        //B[n].nd[B[n].m];
        while (input<0 || input>10 ||cin.fail())
        {
          B[n].A.pop_back();
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Ivedete netinkama reiksme \n";
          cin >> input;
          B[n].A.push_back(input);
        }
        cout << "Ar norite ivesti dar viena pazymi?\n Jei taip - spauskite 1 \n Jei ne - iveskite bet kokia kita reiksme \n";
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
    cout << "Ar norite ivesti dar vieno mokinio duomenis? \n Jei taip, spauskite 1 \n Jei ne, iveskite bet kokia kita reiksme \n";
    cin >> check;
  }while(check==1);


    cout << "Kokiu budu norite apskaiciuoti bala? \n Mediana - spauskite 1 \n Vidurkiu - iveskite bet kokia kita reiksme \n";
    cin >> cchoice;
    if (cchoice==1)
    {
      for (int e=0; e<n; e++)
      {
        B[e].total=0.4*median(B[e].A)+0.6*B[e].egz;
      }
      cout << "Pavarde            Vardas          Galutinis(Med.)" << endl;
      cout <<"---------------------------------------------------"<<endl;
      for (int i=0; i<n; i++)
      {
        cout << B[i].name << "          " << B[i].lastName << "        " << fixed << setprecision(2) << B[i].total << endl;
      }
    }
    else
    {
      for (int e=0; e<n; e++)
      {
        B[e].total=0.4*average(B[e].A)+0.6*B[e].egz;
      }
      cout << "Vardas            Pavarde          Galutinis(Vid.)" << endl;
      cout <<"---------------------------------------------------"<<endl;
      for (int i=0; i<n; i++)
      {
        cout << B[i].name << "          " << B[i].lastName << "        " << fixed << setprecision(2) << B[i].total << endl;
      }
    }
  return 0;
}
double median (vector<int> A)
{
  int a, b;//lakikini kintamieji medianos skaiciavimui
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
