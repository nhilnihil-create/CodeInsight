#include<iostream>
using namespace std;

int main(){
    string s;cin>>s;
    int n = s.size();
    cout<<(s[0]==s[n-1]^n%2?"First":"Second")<<'\n';
}
