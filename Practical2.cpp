#include<iostream>
using namespace std;

int main(){
    int a[2][2];
    cout<<"a11 a12 a21 a22: "<<endl;
    cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
    int adjA[2][2];

    adjA[0][0]=a[1][1];
    adjA[1][1]=a[0][0];
    adjA[0][1]=-a[0][1];
    adjA[1][0]=-a[1][0];

    int d=a[0][0]*a[1][1]-(a[0][1]*a[1][0]);

    int r1=d,r2=26;

    if(r1<r2){
        int temp=r1;
        r1=r2;
        r2=temp;
    }

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
        return 0;
    }
    else{
        if(t1<0){
            t1+=26;
        }
        if(t1>=26){
            t1=t1%26;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(adjA[i][j]<0){
                adjA[i][j]=adjA[i][j]+26;
            }
            if(adjA[i][j]>=26){
                adjA[i][j]=adjA[i][j]%26;
            }
            adjA[i][j]*=t1;
            if(adjA[i][j]>=26){
                adjA[i][j]=adjA[i][j]%26;
            }
        }
    }

    cout<<"Inverse: "<<endl;
    cout<<adjA[0][0]<<" "<<adjA[0][1]<<endl;
    cout<<adjA[1][0]<<" "<<adjA[1][1]<<endl;
    return 0;
}


