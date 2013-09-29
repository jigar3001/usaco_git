/*
ID: jigarra1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  
  int weekdays[7],prevDay=0,n;
  for(int i=0;i<7;i++)
  {
    weekdays[i]=0;
  }
  weekdays[0]=1;
  fin>>n;
  for(int j=1900;j<1900+n;j++){
  for(int i=1;i<=12;i++)
  {
    switch(i)
    {
      case 3:if(j%4==0 && j%100!=0 || j%400==0)
	      {
		  weekdays[(prevDay+1)%7]++;
		  prevDay=(prevDay+1)%7;
	      }
	      else
	      {
		  weekdays[(prevDay)%7]++;
		  prevDay=(prevDay)%7;
	      }
	      break;
      
      case 2:
      case 4:
      case 6:
      case 8:
      case 9:
      case 11:
      case 1:
	     if(j!=1900 || i!=1){
	     weekdays[(prevDay+3)%7]++;
	     prevDay=(prevDay+3)%7;
	     }
	     break;

      case 5:
      case 7:
      case 10:
      case 12:weekdays[(prevDay+2)%7]++;
	      prevDay=(prevDay+2)%7;
	      break;
    }
  }
  }
  for(int i=0;i<7;i++)
  {
    if(i==6)
      fout<<weekdays[i]<<endl;
    else
      fout<<weekdays[i]<<" ";
  }
  
  return 0;
}