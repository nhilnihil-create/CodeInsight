#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main() {
  ll n,c,k;cin>>n>>c>>k;
  vector<ll> v(n);
  rep(i,n){cin>>v[i];}
  sort(v.begin(),v.end());
  ll i=0;
  
  ll ans=0;
  while(true){
    if(i>=n)break;
    ll j=1;
    while(true){
      if(i+j>=n||j==c||v[i+j]>v[i]+k){ans++;break;}
      else{j++;}
    }
  i+=j;//cout<<i<<" ";
  }
  cout<<ans;
}