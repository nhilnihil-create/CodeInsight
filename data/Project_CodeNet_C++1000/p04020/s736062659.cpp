#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
int main() {
ll n;
cin>>n;
ll f=0;
ll counter=0;
ll a[n+2]={};
for(ll i=1; i<=n; i++){
cin>>a[i];}
for(ll i=1; i<=n; i++){
if(a[i]%2==0){
counter+=a[i]/2;
continue;}
else if(a[i+1]>0){
counter+=a[i]/2;
counter++;
a[i+1]--;}
else{
counter+=a[i]/2;}}
cout<<counter<<endl;}
