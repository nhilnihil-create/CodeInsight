#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pll = pair<ll, ll>;

int main() {
  ll n; cin>>n;
  vector<pll> v(n);
  rep(i,n){cin>>v[i].first>>v[i].second;}
  ll ans=0;
  for(int i=n-1; i>=0; i--){
    ll a =  (v[i].first+ans) % v[i].second;
    if(a !=0){ans+= v[i].second-a;}
  }
  cout<<ans;
}
   