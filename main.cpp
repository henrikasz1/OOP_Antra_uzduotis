#include "functions.h"

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
    try
    {
    ifstream in ("kursiokai.txt");
    if (!in.good())
    {
      throw "failas neegzistuoja \n";
    }
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
    catch(const char* a)
    {
      cout << a << endl;
    }
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
