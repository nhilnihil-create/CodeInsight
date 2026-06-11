#include <bits/stdc++.h>
using namespace std;
int main() {
long long counter=0;
long long n;
cin>>n;
long long a;
cin>>a;
long long odd=0;
long long asd=0;
for(long long i=0;i<n;i++){
cin>>counter;
if(counter%2==0){
asd++;}
else{
odd++;}}
if(odd==0){
if(a==0){
counter=pow(2,n);
cout<<counter<<endl;}
else{
cout<<0<<endl;}}
else{counter=pow(2,n-1);
cout<<counter<<endl;}}
