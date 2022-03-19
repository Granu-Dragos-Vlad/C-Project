#ifndef Dispersie_H_
#define Dispersie_H_
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000
using namespace std;
vector <int> vect;
vector <int> vfinal;
vector <int> vinitial;
int primM(int n)
{
    for(int i=n+1;i<INF;++i)
    {
        int OK=1;
        if(i<2)
        {
            OK=0;
        }
        for(int d=2;d*d<=i && OK==1;++d)
        {
            if(i%d==0)
            {
                OK=0;
            }
        }
        if(OK==1)
        {
            return i;
        }
    }
    return 0;
}
vector<int> dispersiedubla(vector<int> vinitial,int m,int i)
{
    vfinal.resize(vinitial.size());
    int OK=0;
    while(OK==0)
    {
        for(int k=0;k<vinitial.size();++k)
        {
          if(count(vfinal.begin(),vfinal.end(),vinitial[k])==0 || count(vinitial.begin(),vinitial.end(),vinitial[k])>1)
          {
            if(count(vfinal.begin(),vfinal.end(),vinitial[k])!=count(vinitial.begin(),vinitial.end(),vinitial[k]))
            {
             int poz=(vinitial[k]%m+i*vinitial[k]%m)%m;
             if(vfinal[poz]==0)
             {
                vfinal[poz]=vinitial[k];
             }
            }
        }
        if(count(vfinal.begin(),vfinal.end(),0)==0)
        {
            OK=1;
        }
        i++;
       }
    }
    return vfinal;

}
#endif /* Dispersie_H_ */

