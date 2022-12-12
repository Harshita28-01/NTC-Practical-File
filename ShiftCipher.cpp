#include<iostream>
using namespace std;

int main(){
    int n,shift;
    cout<<"Enter the length of the string: "<<endl;
    cin>>n;

    char str[n];
    cout<<"Enter the plaintext(in capital letters): "<<endl;
    cin>>str;

    cout<<"Enter the shift character: "<<endl;
    cin>>shift;

    for(int i=0;i<n;i++){
        str[i]=(((int)str[i]-65+shift)%26)+65;
    }
    cout<<"Ciphertext: "<<str<<endl;
    return 0;
}
