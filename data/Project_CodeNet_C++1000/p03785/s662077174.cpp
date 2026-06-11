#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main() {
ll n,c,k;
cin>>n>>c>>k;
ll t[n]={};
ll bas=0;
ll a=0;
ll b=0;
for(ll i=0; i<n; i++){
cin>>t[i];}
sort(t,t+n);
for(ll i=0; i<n; i++){
ll r=t[i]+k;
bas++;
a=i;
while(t[a]<=r&&b<c){
b++;
a++;
}
i=a-1;
b=0;}
cout<<bas<<endl;}
