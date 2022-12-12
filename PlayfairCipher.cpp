#include<iostream>
using namespace std;

struct Pos{
    public:
    int row;
    int col;
};

Pos search(char ch,char mat[5][5]){
    Pos ans;
    if(ch=='J'){
        ch='I';
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(mat[i][j]==ch){
                ans.row=i;
                ans.col=j;
                return ans;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the length of the string: ";
    cin>>n;

    char str[n];
    cout<<"Enter the plaintext(in capital letters): ";
    cin>>str;

    int keyLen;
    cout<<"Enter the length of the key: ";
    cin>>keyLen;
    char key[keyLen];
    cout<<"Enter the value of the key: ";
    cin>>key;

    char alpha[26];
    for(int i=0;i<26;i++){
        alpha[i]=0;
    }
    
    //developing key matrix
    char mat[5][5];
    int i=0;
    int j=0;
    for(int k=0;k<keyLen;k++){
        if(alpha[key[k]-65]==0){
            mat[i][j]=key[k];
            j++;
            if(j==5){
                i++;
                j=0;
            }
            alpha[key[k]-65]=1;
        }
    }

    for(int k=0;k<26;k++){
        if(alpha[k]==0 && k!=9){
            mat[i][j]=k+65;
            j++;
            if(j==5){
                i++;
                j=0;
            }
            alpha[k]=1;
        }
    }
    
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int len=n;
    for(i=1;i<n;i++){
        if(str[i-1]==str[i]){
            len++;
        }
    }
    if(len%2!=0){
        len++;
    }
    // cout<<len<<endl;

    char pt[len];
    pt[0]=str[0];
    int k=1;
    for(i=1;i<n && k<len;i++){
        if(str[i-1]==str[i]){
            pt[k]='Z';
            k++;
        }
        pt[k]=str[i];
        // cout<<str<<" "<<pt<<endl;
        k++;
    }
    if(k<len){
        pt[len-1]='Z';
    }

    // cout<<pt<<endl;
    // for(int i=0;i<len;i++){
    //     cout<<i<<" -> "<<pt[i]<<endl;
    // }
    
    char ct[len];
    k=0;
    // cout<<pt<<endl;
    // cout<<len<<endl;
    for(int i=0;i<len-1;i+=2){
        Pos first=search(pt[i],mat);
        Pos second=search(pt[i+1],mat);
        // cout<<pt[i]<<" "<<first.row<<" "<<first.col<<endl;
        // cout<<pt[i+1]<<" "<<second.row<<" "<<second.col<<endl;
        if(first.row==second.row){
            ct[k++]=mat[first.row][(first.col+1)%5];
            ct[k++]=mat[second.row][(second.col+1)%5];
        }
        else if(first.col==second.col){
            ct[k++]=mat[(first.row+1)%5][first.col];
            ct[k++]=mat[(second.row+1)%5][second.col];
        }
        else{
            ct[k++]=mat[first.row][second.col];
            ct[k++]=mat[second.row][first.col];
        }
    }
    
    for(int i=0;i<len;i++){
        cout<<ct[i];
    }
    // cout<<ct<<endl;
    return 0;
}
