#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
ll n;
cin>>n;
ll a[n]={};
ll b[n]={};
cin>>a[0];
b[0]=a[0];
for(ll i=1; i<n; i++){
cin>>a[i];
b[i]=b[i-1]+a[i];}
ll S=b[n-1];
ll x=0;
ll y=0;
ll counter=1000000000000;
for(ll i=0; i<n-1; i++){
x=b[i];
y=S-b[i];
counter=min(abs(x-y), counter);}
cout<<counter<<endl;}
