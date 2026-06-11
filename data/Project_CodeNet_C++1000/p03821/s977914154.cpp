#include <bits/stdc++.h>
using namespace std;
int main() {
long long counter=0;
long long n;
cin>>n;
long long b[n]={};
long long a[n]={};
for(long long i=0; i<n; i++){
cin>>a[i]>>b[i];}
for(long long i=n-1; i>=0; i--){
if((a[i]+counter)%b[i]==0){
continue;}
else{
counter+=b[i]-(a[i]+counter)%b[i];}}
cout<<counter<<endl;}

