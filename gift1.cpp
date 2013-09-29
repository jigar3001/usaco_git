/*
ID: jigarra1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct person{
  int amount;
  int balance;
  char name[20];
};

int main()
{

   ifstream fin("gift1.in");
   ofstream fout("gift1.out");

  char name1[20]="",name[20]="";
  int np,n,l;
  fin>>np;

  person p[np];

  for( int i=0;i<np;i++)
  {

    fin>>p[i].name;
    p[i].balance=0;
    p[i].amount=0;
  }

  for( int i=0;i<np;i++)
  {
    fin>>name;
    for(int var=0;var<np;var++)
    {
      if(strcmp(p[var].name,name)==0)
	 l=var;
    }
    fin>>p[l].amount>>n;
    if(n!=0){
      p[l].balance+=((p[l].amount)%n)-p[l].amount;
    for(int j=0;j<n;j++)
    {
      
      fin>>name1;
      for( int k=0;k<np;k++)
      {
	if(strcmp(name1,p[k].name)==0){
	  p[k].balance+=(p[l].amount/n);
	}
      }
     }
    }
  }
  for( int i=0;i<np;i++)
  {
    fout<<p[i].name<<" "<<p[i].balance<<endl;
  }
  return 0;
}