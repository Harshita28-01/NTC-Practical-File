#include<iostream>
using namespace std;

int main(){
    int r1,r2;
    cout<<"Enter the domain: ";
    cin>>r1;
    cout<<"Enter the number for which inverse is to be calculated: ";
    cin>>r2;
    
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

    if(r1!=1){
        cout<<"Multiplicative Inverse does not exist!"<<endl;
    }
    else{
        if(t1<0){
            cout<<"Multiplicative Inverse: "<<t1+n;
        }
        else{
            cout<<"Multiplicative Inverse: "<<t1;
        }
    }
    return 0;
}
