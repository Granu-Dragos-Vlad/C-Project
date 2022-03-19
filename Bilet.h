#ifndef Bilet_H_
#define Bilet_H_
#include <iostream>
using namespace std;
int a;
string b,c;
class Bilet
{
    private:
    int pret;
    string cod;
    string ora;
    public:
    void setOra(string o)
    {
        this->ora=o;
    }
    string getOra()
    {
        return this->ora;
    }
    void setCod(string c)
    {
        this->cod=c;
    }
    string getCod()
    {
        return this->cod;
    }
    void setPret(int p)
    {
        this->pret=p;
    }
    int getPret()
    {
        return this->pret;
    }
    Bilet(int,string,string);
    friend ostream & operator << (ostream &, const Bilet &);

};
Bilet::Bilet(int a,string b,string c)
{
    this->pret=a;
    this->cod=b;
    this->ora=c;
}
ostream & operator << (ostream &st, const Bilet &x)
{
  st<<"Biletul are pretul "<<x.pret<<" , codul "<<x.cod<<" si ora "<<x.ora;
  return st;
}
#endif /* Bilet_H_ */

