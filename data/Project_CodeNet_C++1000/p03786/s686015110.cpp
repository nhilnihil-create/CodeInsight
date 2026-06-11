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
ll f=0;
ll q=1;
ll w=0;
for(ll i=0; i<n; i++){
cin>>a[i];}
sort(a,a+n);
for(ll i=0; i<n; i++){
if(2*f>=a[i]){
q++;}
else{q=1;}
f+=a[i];}
cout<<q<<endl;}
