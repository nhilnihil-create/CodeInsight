#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll> 
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

const ll mod=1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,a,ans=0;cin>>n;
  map<ll,ll> mp;rep(i,n) {cin>>a;mp[a]++;}
  vector<P> v;
  for(auto i:mp) v.emplace_back(P(i.first,i.second));
  ll l=v.size();
  bool isok=true;
  if(n%2==0) {
    if(v[0].first==1&&v[0].second==2) {
      for(ll i=1;i<l;++i)
        if(!(v[i].first==2*i+1&&v[i].second==2)) {isok=false;break;}
      if(isok) {
        ans=1;
        rep(i,l) ans=(ans*2)%mod;
      }
    }
  }
  else {
    if(v[0].first==0&&v[0].second==1) {
      for(ll i=1;i<l;++i)
        if(!(v[i].first==2*i&&v[i].second==2)) {isok=false;break;}
      if(isok) {
        ans=1;
        rep(i,l-1) ans=(ans*2)%mod;
      }
    }
  }
  print(ans);
  return 0;
}