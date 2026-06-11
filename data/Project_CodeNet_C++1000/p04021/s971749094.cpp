#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;      
int main() {
ll n;
cin>>n;
ll f=0;
ll counter=0;
ll a[n]={};
ll b[n]={};
for(ll i=0; i<n; i++){
cin>>a[i];
b[i]=a[i];}
sort(a,a+n);
ll c[n]={};
for(ll i=0; i<n; i++){
 ll key = b[i];
    auto iter = lower_bound(a, a+n, key);
    if (*iter == key) {
        c[i]=distance(a, iter);}
    }
   
for(ll i=0; i<n; i++){
if(c[i]%2==i%2){
continue;}
else{
counter++;}}
counter/=2;
cout<<counter<<endl;}
