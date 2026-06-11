#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using Graph=vector<vector<ll>>;
int main(){
  ll n,c=0;cin>>n;
  vector<ll> x(100010);
  rep(i,n){
    ll a;cin>>a;a++;
    x[a-1]++;
    x[a]++;
    x[a+1]++;
  }
  rep(i,100010)c=max(c,x[i]);
  cout<<c;
}