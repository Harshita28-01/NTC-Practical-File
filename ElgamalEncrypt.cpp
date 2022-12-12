#include<iostream>
#include<math.h>
using namespace std;

int main() {
    double p=11;
    double e1=2;
    double d=3; 
    double temp=pow(e1,d);
    double e2=fmod(temp,p);
    double r=4;
    temp=pow(e1,r);
    double c1=fmod(temp,p);
    temp=pow(e2,r);
    double pt=7;
    temp=temp*pt;
    double c2=fmod(temp,p);
    
    cout<<"Original Message = "<<pt;
    cout<<"\n"<<"p = "<<p;
    cout<<"\n"<<"d = "<<d;
    cout<<"\n"<<"e1 = "<<e1;
    cout<<"\n"<<"e2 = "<<e2;
    cout<<"\n"<<"Ciphertext:-";
    cout<<"\n"<<"c1 = "<<c1;
    cout<<"\n"<<"c2 = "<<c2;
    return 0;
}