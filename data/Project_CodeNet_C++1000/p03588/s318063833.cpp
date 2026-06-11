#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
// nCk を取得
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll n;
cin>>n;
ll a[n]={};
ll b[n]={};
for(ll i=0; i<n; i++){
cin>>a[i]>>b[i];}
ll ca=0;
ll cb=10000000000;
for(ll i=0; i<n; i++){
ca=max(ca,a[i]);
cb=min(cb,a[i]);}
ll ba=0;
ll bi=0;
ll bb=0;
ll bn=0;
for(ll i=0; i<n; i++){
if(a[i]==ca){
ba=b[i];
bb=i;}
if(cb==a[i]){
bi=b[i];
bn=i;}}
cout << ca+ba << endl;}
