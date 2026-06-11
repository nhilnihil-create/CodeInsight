#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
 long long n,m;
 cin>>n>>m;
 long long a,b;
 long long path[n+100];
 for(long long i=0;i<n;i++){
  path[i]=0;
 }
 for(long long i=0;i<m;i++){
  cin>>a>>b;
  path[a-1]++;
  path[b-1]++;
 }
 for(long long i=0;i<n;i++){
  printf("%lld\n",path[i]);
 }
return 0;}