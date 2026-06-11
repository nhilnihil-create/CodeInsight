#include <bits/stdc++.h>
using namespace std;
int main() {
long long counter=0;
long long n;
cin>>n;
long long a[n]={};
long long f=0;
for(long long i=0; i<n; i++){
cin>>a[i];}
for(long long i=0; i<n-1; i++){
if(a[i]==a[i+1]){
continue;}
else if(a[i]<a[i+1]){
if(f==0){
f++;
continue;}
else if(f==1){
continue;}
else{
counter++;
f=0;
continue;}}
else{
if(f==0){
f+=2;
continue;}
else if(f==2){
continue;}
else{
counter++;
f=0;
continue;}}}
cout<<counter+1<<endl;}

