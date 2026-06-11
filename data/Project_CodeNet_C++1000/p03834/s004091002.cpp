#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i=0;i<5;i++)cout<<s[i];
    cout<<" ";
    for(int i=6;i<13;i++)cout<<s[i];
    cout<<" ";
    for(int i=14;i<19;i++)cout<<s[i];
    cout<<endl;
    return 0;
}