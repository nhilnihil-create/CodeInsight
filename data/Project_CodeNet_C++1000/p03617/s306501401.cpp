#include <bits/stdc++.h>
using namespace std;
int main() {
long long counter=0;
long long n,a,s,d,r;
cin>>n>>a>>s>>d>>r;
long long b[3]={};
b[0]=n*4;
b[1]=a*2;
b[2]=s;
sort(b,b+3);
if(b[0]*2<=d){
cout<<r*b[0]<<endl;}
else if(r%2==0){
cout<<r/2*d<<endl;}
else{
cout<<(r-1)/2*d+b[0]<<endl;}}
