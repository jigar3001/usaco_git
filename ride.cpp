/*
ID: jigarra1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  long int cometProduct=1,groupProduct=1;
  char comet[100], group[100];
  
  fin>>comet>>group;  
  
  for(int i=0;i<strlen(comet);i++)
  {
    cometProduct*=((int)comet[i]-64);
  }
  for(int i=0;i<strlen(group);i++)
  {
    groupProduct*=((int)group[i]-64);
  }
  if(cometProduct%47==groupProduct%47)
    fout<<"GO"<<endl;
  else
    fout<<"STAY"<<endl;
  
  return 0;
}