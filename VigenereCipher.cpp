#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length of the string: ";
    cin>>n;

    char str[n];
    cout<<"Enter the plaintext(in capital letters): ";
    cin>>str;

    int m;
    cout<<"Enter the length of the key: ";
    cin>>m;

    char key[m];
    cout<<"Enter the key(in capital letters): ";
    cin>>key;
   
    int pt[n];
    
    for(int i=0;i<n;i++){
        pt[i]=str[i]-65;
    }

    int keyMat[m];

    for(int i=0;i<m;i++){
        keyMat[i]=((int)key[i])-65;
    }
     
    char cipher[n];
    int k=0;
    cout<<endl;
    for(int i=0;i<n;i++){
        cipher[i]=(char)(((pt[i]+keyMat[k%m])%26)+65);
        k++;
    }

    cout<<"Ciphertext: ";
    for(int i=0;i<n;i++){
        cout<<cipher[i];
    }
    return 0;
}
