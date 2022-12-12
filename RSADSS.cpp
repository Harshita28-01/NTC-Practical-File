#include<iostream>
#include<math.h>
using namespace std;
int multiinv(int domain,int number){
    int r1=domain,r2=number;
    if(r1<r2){
        int temp=r1;
        r1=r2;
        r2=temp;
    }
    int n=r1;
    int t1=0;
    int t2=1;
    int t=0; 
    int r=0;
    int q=0;
    while(r2!=0){
        q=r1/r2;
        r=r1%r2;
        t=t1-t2*q;
        t1=t2;
        t2=t;
        r1=r2;
        r2=r;
    }
    
    if(t1<0){
        return t1+n;
    }
    else{
        return t1;
    }
}
int main() {
   //2 random prime numbers
   double p = 3;
   double q = 11;
   double n=p*q;//calculate n
   double track;
   double phi= (p-1)*(q-1);//calculate phi
   //public key
   //e stands for encrypt
   double e=7;
   double d = multiinv(phi,e);
   //private key
   //d stands for decrypt
   //choosing d such that it satisfies d*e = 1 mod phi
   double message = 31;
   double s = pow(message,d); //sign the document using private key
   double m = pow(s,e);
   s=(int)s%(int)n;
   m=(int)m%(int)n;
   if(m<0){
    m=m+n;
   }
   if(s<0){
    s=s+n;
   }
   cout<<"Original Message = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"Message sent: "<< message<< " + "<<s;
   
   if(m==message){
    cout<<"\nAccept the message!";
   }
   else{
    cout<<"\nDiscard the message!";
   }
   return 0;
}