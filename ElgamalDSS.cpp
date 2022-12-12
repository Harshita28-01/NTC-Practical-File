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
    double p=11;double e1=2;
    double d=3;double r=4; 
    double M=31;
    double temp=pow(e1,d);
    double e2=(int)temp%(int)p;
    if(e2<0){
        e2+=p;
    }
    temp=pow(e1,r);
    double s1=(int)temp%(int)p;
    if(s1<0){
        s1+=p;
    }
    double rinv=multiinv(p,r);
    temp=(M-d*s1)*rinv;
    double s2=(int)temp%(int)(p-1);
    if(s2<0){
        s2+=(p-1);
    }
    cout<<"Original Message = "<<M;
    cout<<"\n"<<"S1 = "<<s1;
    cout<<"\n"<<"S2 = "<<s2;

    if(s1>0 && s1<p && s2>0 && s2<p-1){
        temp=pow(e1,M);
        double v1=(int)temp%(int)p;
        if(v1<0){
            v1+=p;
        }
        double temp1=pow(e2,s1);
        double temp2=pow(s1,s2);
        double v2=(int)(temp1*temp2)%(int)p;
        if(v2<0){
            v2+=p;
        }
        if(v1==v2){
            cout<<"\nAccept the message!";
        }
        else{
            cout<<"\nDiscard the message!";
        }
    }
    else{
        cout<<"\nDiscard the message!";
    }
    return 0;
}