#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  
  rep(i,n) cin >> a[i];
  
  ll ans=1;
  rep(i,n) ans = lcm(ans,a[i]);
  
  cout << ans << endl;
  
  return(0);
}