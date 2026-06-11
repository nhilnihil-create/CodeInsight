#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using Graph=vector<vector<ll>>;
int main(){
  int n;cin>>n;
  map<ll,ll> a;
  for(int i=0;i<n;++i){
    ll x;cin>>x;
    a[x]++;
  }
  ll c=0;
  for(auto it=a.begin();it!=a.end();++it){
    int t=it->second;
    if(t&1)c++;
  }
  cout<<c;
}