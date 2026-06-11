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
ll n,a,b;
cin>>n>>a>>b;
string s;
cin>>s;
ll k=0;
ll g=0;
for(ll i=0; i<s.size(); i++){
if(s.at(i)=='a'&&k+g<a+b){
cout << "Yes" << endl;
k++;}
else if(s.at(i)=='b'&&(k+g<a+b)&&g<b){
cout << "Yes" << endl;
g++;}
else{
cout << "No" << endl;}}}


