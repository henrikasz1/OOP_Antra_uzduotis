#include "functions.h"
#include "struct.h"

double median (vector<int> &A)
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
double average (vector<int> &A)
{
  int total=0;
  for(int i=0; i<A.size(); i++)
  {
    total+=A[i];
  }
  return total*1.0/A.size();
}
void output (int n, vector<data> &B)
{
      system("cls");
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
void generateFile(int kiekis, int nddydis, string &a)
{
    auto start = std::chrono::steady_clock::now();
    srand(time(NULL));
    string vardas= "vardas";
    string pavarde= "pavarde";
    string nd="ND";
    string egz="EGZ";
    stringstream numOfFile;
    numOfFile << kiekis;
    string num=numOfFile.str();
    a="randomly_generated_file_of "+num+".txt";
    ofstream fd(a);
    fd << left << setw(20) << vardas << left << setw(20) << pavarde;
    for (int i=1; i<=nddydis; i++)
    {
        fd << setw(5) << right << nd << i << " ";
    }
    fd << setw(5) << right << egz << endl;
    for(int j=1; j<=kiekis; j++)
    {
        fd << vardas << j;
        fd << setw(20-displayHelper(j)) << right;
        fd << pavarde << j;
        for (int k=0; k<nddydis; k++)
        {
            if (k==0)
            {
                fd << right << setw(18-displayHelper(j)) << rand()%10+1;
            }
            else fd << right << setw(7) << rand()%10+1;
        }
        fd << right << setw(7) << rand()%10+1 << endl;
    }
    fd.close();
    auto finish = std::chrono::steady_clock::now();
    cout<<"Faila sugeneravo per: "<<std::chrono::duration <double, milli>(finish - start).count()<<" ms"<<endl;
}
int displayHelper (int number)
{
    int temp=0;
    while (number>0)//kadangi integeris suroundina, galima rasyt tokia salyga
    {
        number/=10;
        temp++;
    }
    return temp;
}
void readFile(vector<data> &M, string name, int &k, int nddydis)
{
    auto start = std::chrono::steady_clock::now();
    k=0;
    int nd;
    ifstream in(name);
    in.ignore(256,'\n'); //skipina pirma eilute
    while(!in.eof())
    {
        M.push_back(data());
        in >> M[k].name >> M[k].lastName;
        for (int i=0; i<nddydis; i++)
        {
            in >> nd;
            M[k].A.push_back(nd);
        }
        in >> M[k].egz;
        M[k].median=0.4*median(M[k].A)+0.6*M[k].egz;
        M[k].average=0.4*average(M[k].A)+0.6*M[k].egz;
        if (in.eof())
        {
            break;
        }
        k++;

    }
    M.shrink_to_fit();
    auto finish = std::chrono::steady_clock::now();
    cout<<"Faila nuskaite per: "<<std::chrono::duration <double, milli>(finish - start).count()<<" ms"<<endl;
    in.close();
}
void distributeFile(int numOfStudents, int k, vector<data> &M)
{
    auto start = std::chrono::steady_clock::now();
    stringstream number;
    number << numOfStudents;
    string num=number.str();
    ofstream bad("apgailetini "+num+".txt");
    ofstream good("dievai "+num+".txt");
    for (int i=0; i<k; i++)
    {
        if (M[i].average<5)
        {
            bad.width(15);
            bad << left << M[i].name;
            bad.width(15);
            bad << left << M[i].lastName;
            bad.width(15);
            bad << left << M[i].median;
            bad.width(15);
            bad << left << M[i].average << endl;
        }
        else if (M[i].average>=5)
        {
            good.width(15);
            good << left << M[i].name;
            good.width(15);
            good << left << M[i].lastName;
            good.width(15);
            good << left << M[i].median;
            good.width(15);
            good << left << M[i].average << endl;
        }
    }
    auto finish = std::chrono::steady_clock::now();
    cout << "Studentus surusiavo ir isvede i naujus failus per: " << std::chrono::duration <double, milli>(finish - start).count() << "ms" << endl;
}
