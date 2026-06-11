#include<iostream>
using namespace std;
string s,a="CODEFESTIVAL2016";
int c;
int main(){
cin>>s;
for(int i=0;i<16;i++)
if(s[i]!=a[i]) c++;
cout<<c<<endl;}