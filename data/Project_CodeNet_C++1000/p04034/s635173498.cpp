#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
int main() {
ll n,m;
cin>>n>>m;
ll f=0;
ll counter=0;
ll a[m]={};
ll b[m]={};
ll c[n+1]={};
for(ll i=0; i<=n; i++){
c[i]=1;}
set <ll> q;
q.insert(1);
for(ll i=0; i<m; i++){
cin>>a[i]>>b[i];}
for(ll i=0; i<m; i++){
if(q.count(a[i])&&c[a[i]]>=2){
q.insert(a[i]);
q.insert(b[i]);
c[a[i]]--;
c[b[i]]++;}
else if(q.count(a[i])&&c[a[i]]==1){
q.erase(a[i]);
q.insert(b[i]);
c[a[i]]--;
c[b[i]]++;}
else {
c[a[i]]--;
c[b[i]]++;}}
cout<<q.size()<<endl;}