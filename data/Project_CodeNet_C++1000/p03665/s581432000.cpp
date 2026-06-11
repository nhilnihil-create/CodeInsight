#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

// nCk
ll comb(ll n, ll k) {
  ll ret = 1;
  ll x = min(n-k, k);
  for(ll cnt = 1; cnt <= x; cnt++) {
    ret *= (n-x+cnt);
    ret /= cnt;
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n, p;
  cin >> n >> p;
  
  ll odd = 0;
  ll even = 0;
  
  vector<ll> a(n);
  rep(i, 0, n) {
    cin >> a[i];
    if(a[i]%2==0) even++;
    else odd++;
  }
  
  ll ans = 0;
  if(p%2==0) {
    for(ll i=0; i<=odd; i+=2) ans += comb(odd, i);
    ans *= (ll)pow(2, even);
  }
  else {
    for(ll i=1; i<=odd; i+=2) ans += comb(odd, i);
    ans *= (ll)pow(2, even);
  }
  
  cout << ans << "\n";
}