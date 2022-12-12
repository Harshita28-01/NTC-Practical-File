#include<iostream>
using namespace std;

int main(){
    int n,key;
    cout<<"Enter the length of the string: ";
    cin>>n;

    char str[n];
    cout<<"Enter the plaintext(in capital letters): ";
    cin>>str;

    cout<<"Enter the value of the key: ";
    cin>>key;

    char mat[key][n];
    for(int i=0;i<key;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=' ';
        }
    }
    int i=0;
    //true means we want to go in increasing direction of row number
    //false means we want to go in decreasing direction of row number 
    int flag=true;
    for(int j=0;j<n;j++){
        mat[i][j]=str[j];
        if(i==0){
            flag=true;
        }
        if(i==key-1){
            flag=false;
        }
        if(flag==true){
            i=(i+1)%key;
        }
        else{
            i=(i-1)%key;
        }
    }
    char ct[n];
    int k=0;
    for(int i=0;i<key;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=' '){
                ct[k++]=mat[i][j];
            }
        }
    }
    cout<<"Ciphertext: ";
    for(int i=0;i<n;i++){
        cout<<ct[i];
    }
    return 0;
}
