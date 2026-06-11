#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;
const ll INF = 999999999999;


int main(){
  ll n;cin >> n;
  vector<ll> a(n*3);
  rep(i,n*3) cin >> a.at(i);
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll ans = 0;
  ll cnt = 0;
  for(ll i=1;i<2*n;i+=2){
    ans += a.at(i);
  }
  cout << ans << endl;

  return 0;
}
