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
ll a,b,x;
cin>>a>>b>>x;
ll aa,bb;
aa=a/x;
bb=b/x;
if(a==0){
cout<<b/x+1<<endl;}
else if(a%x==0){
cout<<bb-aa+1<<endl;}
else{
cout<<bb-aa;}}