#ifndef Dijkstra_H_
#define Dijkstra_H_
#include <iostream>
#include <queue>
#include <vector>
#define INF 100000
using namespace std;
queue <int> q;
vector <int> G[1000],C[100];
int i,n,x,y,z,d[1000],p,m;
void calcdist(int n,int m,int p)
{
    for(int i=1;i<=n;++i)
    {
        d[i]=INF;
    }
    cout<<"Vom introduce "<<m<<" triplete unde primul numar este nodinitial,al doilea numar nodfinal si al treilea numar costul! "<<endl;
    for(i=1;i<=m;++i)
    {
        cin>>x>>y>>z;
        G[x].push_back(y);
        C[x].push_back(z);
    }
    q.push(p);
    d[p]=0;
    while(!q.empty())
    {
        x=q.front();
        for(i=0;i<G[x].size();++i)
            if(d[G[x][i]]>d[x]+C[x][i])
            {
                ///relaxare muchii
                d[G[x][i]] = d[x] + C[x][i];
                q.push(G[x][i]);
            }
        q.pop();
    }
    for(i=1;i<=n;++i)
    {
      if(i!=p)
      {
        if(d[i]!=INF)
        {
           cout<<"Distanta de la spectatorul "<<i<<" la stadion " <<" este "<<d[i]<<" "<<endl;
        }
        else cout<<"Nu exista drum de la "<<i<<" la "<<p<<endl;
      }
    }
}
#endif /* Dijkstra_H_ */
