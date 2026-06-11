#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
/*

*/
int main(){
  ll W,H,a,ans=0; cin>>W>>H;
  vector<pair<ll,ll>> V(0,{0,0});
  rep(i,W) cin>>a, V.push_back({a,1LL});
  rep(i,H) cin>>a, V.push_back({a,0LL});
  sort(all(V));
  H++, W++;
  for(auto v: V){
    ll v1=v.first;
    ll v2=v.second;
    if(v2) ans+=v1*H, W--;
    else ans+=v1*W, H--;
  }
  cout<<ans<<endl;
}