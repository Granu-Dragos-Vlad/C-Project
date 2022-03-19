#include <iostream>
#include <vector>
#include "../Bilet.h"
#include "../Dijkstra.h"
#include "../Dispersie.h"
#include "../KMP.h"
using namespace std;
int nrnoduri,nrmuchii,nodstart;
int pr;
string cd,h,pattern,sir;
vector <Bilet> bilete;
vector <int> v;
vector <int> v2;
int main()
{
    cout<<"Introduceti numarul de locatii:";
    cin>>nrnoduri;
    cout<<"Introduceti numarul de strazi:";
    cin>>nrmuchii;
    cout<<"Stadionul este nodul cu numarul:";
    cin>>nodstart;
    calcdist(nrnoduri,nrmuchii,nodstart);
    cout<<endl;
    for(int k=1;k<=nrnoduri-1;++k)
    {
        cout<<"Introduceti pretul,codul si ora biletului " <<k<< ":"<<endl;
        cin>>pr>>cd>>h;
        bilete.push_back(Bilet(pr,cd,h));
    }
    cout<<"Introduceti patternul: ";
    cin>>pattern;
    for(int cnt=0;cnt<bilete.size();++cnt)
    {
        v.push_back(KMP(bilete[cnt].getCod(),pattern));
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    v2=dispersiedubla(v,primM(nrnoduri-1),1);
    cout<<endl;
    for(int i=0;i<v2.size();++i)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<v2.size();++i)
    {
        int poz;
        int OK=1;
        for(int k=0;k<v.size() && OK==1;++k)
        {
            if(v2[i]==v[k])
            {
              poz=k;
              if(count(v.begin(),v.end(),v[k])>1)
              {
                  v[k]=0;
                  OK=0;
              }
            }
        }
        if(poz+1==1)
        {
            cout<<"Spectatorul "<<i+1<<" va intra primul pe stadion"<<endl;
        }
        else  cout<<"Spectatorul "<<i+1<<" va intra al "<<poz+1<<"-lea pe stadion"<<endl;
    }
    return 0;
}
/*
1 2 2
1 3 4
2 3 1
3 5 1
2 4 5
2 5 3
3 4 2
4 6 2
5 6 7
4 5 1
*/
