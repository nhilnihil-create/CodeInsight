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
cout << fixed << setprecision(10);
ll n,k;
cin>>n>>k;
ll s[100005]={};
ll a,b;
ll ca=0;
for(ll i=0; i<n; i++){
cin>>a>>b;
s[a]+=b;}
for(ll i=0; i<=100000; i++){
ca+=s[i];
if(ca>=k){
cout<<i<<endl;
break;}}}
