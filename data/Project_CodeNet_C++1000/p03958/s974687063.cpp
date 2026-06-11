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
ll k,t;
cin>>k>>t;
ll a[t]={};
ll ca = 0 ;
for(ll i=0; i<t; i++){
cin>>a[i];
ca+=a[i];}
sort(a,a+t);
ll ma = a[t-1];
ca=ca-ma;
if(ca>=ma){
cout<<0<<endl;}
else{
cout<<ma-ca-1<<endl;}}
