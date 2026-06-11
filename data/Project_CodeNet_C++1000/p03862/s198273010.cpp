#include <cstring>
#include <iostream>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;
int main(){
long long counter;
counter=0;
long long N,x;
cin>>N>>x;
vector<long long>a(N+10);
vector<long long>b(N+10);
cin>>a.at(0);
for (int i=1;i<N;i++){
cin>>a.at(i);
b.at(i-1)=a.at(i-1)+a.at(i);}
if(a.at(0)-x>=0){counter+=a.at(0)-x;
b.at(0)=x+a.at(1);}
for (int i=0;i<N;i++){
if(b.at(i)-x>=0){
counter+=b.at(i)-x;
b.at(i+1)-=b.at(i)-x;}}
cout<<counter<<endl;}
