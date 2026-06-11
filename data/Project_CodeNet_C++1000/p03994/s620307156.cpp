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
string s;
cin>>s;
ll k;
cin>>k;
ll n=s.size();
ll a[n]={};
for(ll i=0; i<n; i++){
ll c = s.at(i)-'a';
if(c==0) {a[i]=0; continue;}
else { a[i]=26-c;}}
for(ll i=0; i<n; i++){
if(k>=a[i]){
s.at(i)='a';
k-=a[i];}}
k=k%26;
s.at(n-1)+=k;
cout<<s<<endl;}

