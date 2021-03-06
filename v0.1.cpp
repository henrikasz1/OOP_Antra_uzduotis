#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <algorithm>

#define sizeArray 100 //bus naudojama dinaminio masyvo atminciai paskirti

using namespace std;

double median (int n, int A[]);
double average (int n, int A[]);
//void output (int n, data &darray);

struct data{
  string name;//vardas
  string lastName;//pavarde
  int egz;//egzamino rezultatai
  int *nd = new int[sizeArray]; //namu darbai
  double total;//naudojama medianos arba vidurkio isvedimui
  int m=0; //namu darbu rezultatu kiekis
};//struktura

int main ()
{
  data *darray;//dinamines masyvo pointeris
  darray = new data[sizeArray];
  int check=1, choice, cchoice;
  int n=0;//masyvo dydis
  while (check==1)//jeigu 1, ciklas kartojamas, jeigu ivedamas kitas skaicius, ciklas baigiasi, jeigu cin.fail(), ciklas taip pat baigiasi
  {
    cout << "Iveskite mokinio varda\n";
    cin >> darray[n].name;
    for (int p=0; p<darray[n].name.length(); p++)
    {
      while((darray[n].name[p]<'A'|| darray[n].name[p]>'Z')&&(darray[n].name[p]<'a'||darray[n].name[p]>'z'))
      {
          cout << "Ivedete netinkama reiksme, bandykite dar karta \n";
          cin >> darray[n].name;
      }
    }
    cout << "Iveskite mokinio pavarde \n";
    cin >> darray[n].lastName;
    for (int b=0; b<darray[n].lastName.length(); b++)
    {
      while((darray[n].lastName[b]<'A'|| darray[n].lastName[b]>'Z')&&(darray[n].lastName[b]<'a'||darray[n].lastName[b]>'z'))
      {
          cout << "Ivedete netinkama reiksme, bandykite dar karta \n";
          cin >> darray[n].lastName;
      }
    }
    cout << "Ar norite, kad pazymius: \nSugeneruotu automatiskai? - iveskite bet kokia kita reiksme \n Suvestumete patys? - iveskite 1\n";
    cin >> choice;
    int more=1;
    if (choice==1)
    {
      while(more==1)
      {
        cout << "Iveskite pazymi \n";
        cin >> darray[n].nd[darray[n].m];
        while (darray[n].nd[darray[n].m]<0 || darray[n].nd[darray[n].m]>10 ||cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Ivedete netinkama reiskme \n";
          cin >> darray[n].nd[darray[n].m];
        }
        darray[n].m++;
        cout << "Ar norite ivesti dar viena pazymi?\n Jei taip - spauskite 1 \n Jei ne - iveskite bet kokia kita reiksme \n";
        cin >> more;
      }
    }
    else
    {
        darray[n].m=rand()%10+1;
        for (int j=0; j<darray[n].m; j++)
        {
          darray[n].nd[j]=rand()%10+1;
        }
    }
    cout << "Iveskite mokinio egzamino rezultata \n";
    cin >> darray[n].egz;
    while(cin.fail() || darray[n].egz<0 || darray[n].egz>10)
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Egzamino rezultatas gali buti sudarytas tik is skaciu, bandykite dar karta \n";
      cin >> darray[n].egz;
    }
    n++;
    cout << "Ar norite ivesti dar vieno mokinio duomenis? \n Jei taip, spauskite 1 \n Jei ne, iveskite bet kokia kita reiksme \n";
    cin >> check;
  }
    delete []darray;

    cout << "Kokiu budu norite apskaiciuoti bala? \n Mediana - spauskite 1 \n Vidurkiu - iveskite bet kokia kita reiksme \n";
    cin >> cchoice;
    if (cchoice==1)
    {
      for (int e=0; e<n; e++)
      {
        darray[e].total=0.4*median(darray[e].m, darray[e].nd)+0.6*darray[e].egz;
      }
      cout << "Pavarde            Vardas          Galutinis(Med.)" << endl;
      cout <<"---------------------------------------------------"<<endl;
      for (int i=0; i<n; i++)
      {
        cout << darray[i].name << "          " << darray[i].lastName << "        " << fixed << setprecision(2) << darray[i].total << endl;
      }
    }
    else
    {
      for (int e=0; e<n; e++)
      {
        darray[e].total=0.4*average(darray[e].m, darray[e].nd)+0.6*darray[e].egz;
      }
      cout << "Pavarde            Vardas          Galutinis(Vid.)" << endl;
      cout <<"---------------------------------------------------"<<endl;
      for (int i=0; i<n; i++)
      {
        cout << darray[i].name << "          " << darray[i].lastName << "        " << fixed << setprecision(2) << darray[i].total << endl;
      }
    }
  darray=NULL;
  return 0;
}
double median (int n, int A[])
{
  int a, b;//lakikini kintamieji medianos skaiciavimui
  for (int i=0; i<n-1; i++)
  {
    for (int j=i+1; j<n; j++)
    {
      if (A[i]>A[j])
      {
        swap(A[i], A[j]);
      }
    }
  }
  if (n%2==0)
  {
    a=n/2;
    b=n/2-1;
    return (A[a]+A[b])*1.0/2;
  }
  else
  {
    a=n/2;
    return A[a];
  }
}
double average (int n, int A[])
{
  int total=0;
  for(int i=0; i<n; i++)
  {
    total+=A[i];
  }
  return total*1.0/n;
}
