//HonestOrUnkind 2

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll n;cin >> n;
  vector<pair<ll,ll>> ab(n);
  rep(i,n) cin >> ab.at(i).first >> ab.at(i).second;
  sort(ab.begin(),ab.end());
  reverse(ab.begin(),ab.end());
  ll ans = 0;
  ans += ab.front().first + ab.front().second;
  cout << ans << endl;
  return 0;
}