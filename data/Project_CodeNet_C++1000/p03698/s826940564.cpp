#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,x3=0,t;
    string s;set<char>k;
    cin>>s;
    for(int i=0;i<s.size();i++){
        k.insert(s[i]);}
    if(k.size()==s.size())cout<<"yes";
    else cout<<"no";
}