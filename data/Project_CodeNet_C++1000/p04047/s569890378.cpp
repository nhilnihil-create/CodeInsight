#include <bits/stdc++.h>
using namespace std;
int main() {
long long counter=0;
long long n;
cin>>n;
long long d[2*n]={};
for(long long i=0; i<2*n; i++){
cin>>d[i];}
sort(d,d+2*n);
for(long long i=0; i<2*n; i=i+2){
counter+=d[i];}
cout<<counter<<endl;}

