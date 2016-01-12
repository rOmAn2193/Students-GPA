#include <iostream>
#include <fstream>
#include <iomanip>
#include <iomanip>
#include <string>

using namespace std;

struct stype
{
   string first;
   string last;
   string degree;
   int crhrs;
   int id;
   double gpa;
};

const int MAXS=100;
void createm (stype students[MAXS], int & numList )
{
 stype A;
 A.crhrs= -1;
 A.degree= "2";
 A.first= "3";
 A.gpa= -2;
 A.id= -3;
 A.last= "4";
 numList=0;
 for (int i=0; i<MAXS;i++)
	 students[i]=A;
}

bool EmptyList (stype students[MAXS])
{
   for( int i=0;i<MAXS;i++)
   {
	   if(students[i].id !=-3)
		   return false;
   }
   return true;
}
bool fullList (int numList)
{
  if (numList==MAXS)
	  return true;
  else
	  return false;
}

void traverse (stype students[MAXS], int numList, ofstream & outf)
{
  if (!EmptyList(students))
	    for (int i=0; i<numList;i++)
		{
			if (students[i].id != -3)
			{
		 
			 outf << " " << students[i].id << " " << students[i].first << " " << students[i].last << " " << students[i].degree << " " << students[i].crhrs << " " << students[i].gpa << " " << endl;
	   
			}
		}
  else 
	  outf << "The list is Empty!"<< endl;
      outf << endl;
}
void insertem(stype students[MAXS], int & numList, string fname, string lastname, string degree, int crhrs, int id, double gpa)
{
	stype knew;
	knew.first=fname;
	knew.last=lastname;
	knew.degree=degree;
	knew.crhrs=crhrs;
	knew.id=id;
	knew.gpa=gpa;
	if (!fullList(numList))
	{
		if (!EmptyList(students))
		{
			int i=0;
			while(students[i].id !=-3)i++;
            students[i]=knew;
		}
		else
			 students[numList]=knew;

	}
	numList++;
}
void readem (stype students[MAXS], int & numList)
{
	ifstream inf ("Data.dat");
	string fname;
	string lastname;
	string degree;
	int crhrs;
	int id;
	double gpa;
	while (!inf.eof())
	{
		
		inf >> id >> fname >> lastname >> degree >> crhrs >> gpa;
		insertem (students, numList, fname, lastname, degree, crhrs, id, gpa);
		
	}
}

void deletem (stype students[MAXS], int id, int & numList)
{
	for (int i=0;i<MAXS;i++)
	{
		if (students[i].id==id)
		{
			stype A;
			A.crhrs= -1;
			A.degree= "2";
			A.first= "3";
			A.gpa= -2;
			A.id= -3;
			A.last= "4";
			students[i]=A;
			numList--;
		}
	}
	
}

int main ()
{
	ofstream outf("Output.out");
	stype students[MAXS];
	int numList;
	createm (students,numList);
	readem (students, numList);
	traverse (students, numList, outf);
	insertem (students, numList, "Donald", "Shell", "BS", 18, 7676, 3.41);
	deletem (students, 3966, numList); 
	traverse (students, numList, outf);
	system ("pause");
	return 0;
}