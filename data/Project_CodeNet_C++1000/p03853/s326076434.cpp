#include<string>
#include<iostream>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    string s[2*h];
    for(int i=0;i<2*h;i=i+2){
        cin>>s[i];
        s[i+1]=s[i];
    }
    for (int i=0;i<2*h;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}