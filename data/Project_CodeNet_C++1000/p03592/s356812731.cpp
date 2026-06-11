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
ll k,t,l;
cin>>k>>t>>l;
ll m=0;
for(ll i=0; i<=k; i++){
for(ll o=0; o<=t; o++){
if(l==i*t-o*i+o*(k-i))
m++;}}
if(m>0)cout<<"Yes"<<endl;
else cout<<"No"<<endl;}