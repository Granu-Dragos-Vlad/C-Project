#ifndef KMP_H_
#define KMP_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <int> vls;
void lungimeaSuccesorului(string pattern, vector <int> &vls)
{
  int L=0;
  vls[L]=0;
  for(int i=1;i<vls.size();)
  {
    if(pattern[i]==pattern[L])
    {
      L++;
      vls[i]=L;
      i++;
    }
    else
    {
      if(L==0)
      {
        vls[L]=0;
        i++;
      }
      else
      {
        L=vls[L-1];
      }

    }
 }
}
int KMP(string sirinitial, string pattern1)
{
  int Lsirinitial, Lpattern;
  Lsirinitial= sirinitial.length();
  Lpattern=pattern1.length();
  for(int k=0;k<Lpattern;k++)
  {
    vls.push_back(0);
  }
  lungimeaSuccesorului(pattern1, vls);
  int i=0,j=0;
  while(i<Lsirinitial)
  {
    if(pattern1[j]==sirinitial[i])
    {
      i++;
      j++;
    }
    if(j==Lpattern)
    {
      return i-j+1;
      j=vls[j-1];
    }
    else
    {
     if(i<Lsirinitial&& pattern1[j]!=sirinitial[i])
     {
       if(j>0)
       {
         j=vls[j-1];
       }
       else i++;
     }

    }
  }
  return 0;
}
#endif /* KMP_H_ */
