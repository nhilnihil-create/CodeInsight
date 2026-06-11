#include <bits/stdc++.h>
using namespace std;
int main() {
long long counter=0;
long long n;
cin>>n;
long long a,b;
cin>>a>>b;
if(a>b){
cout<<0<<endl;}
else if(a==b){
cout<<1<<endl;}
else if(n==1){
cout<<0<<endl;}
else if(n==2){
cout<<1<<endl;}
else{
cout<<(b*(n-1)+a)-(a*(n-1)+b)+1<<endl;}}