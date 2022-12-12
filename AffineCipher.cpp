#include<iostream>
using namespace std;

int main(){
    int n,multikey,addkey;
    cout<<"Enter the length of the string: "<<endl;
    cin>>n;

    char str[n];
    cout<<"Enter the plaintext(in capital letters): "<<endl;
    cin>>str;

    cout<<"Enter the multiplicative key: "<<endl;
    cin>>multikey;

    cout<<"Enter the additive key: "<<endl;
    cin>>addkey;

    for(int i=0;i<n;i++){
        str[i]=(((((int)str[i]-65)*multikey)+addkey)%26)+65;
    }
    cout<<"Ciphertext: "<<str<<endl;
    return 0;
}
