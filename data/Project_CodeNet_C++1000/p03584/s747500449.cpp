#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a.at(i) >> b.at(i);
  
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if ((k | a.at(i)) == k) ans += b.at(i);
  }
  
  for (int i = 0; i < 31; i++) {
    if ((k & (1 << i)) == 0) continue;
    ll k2 = k ^ (1 << i);
    for (int j = 0; j < i; j++) k2 |= (1 << j);
    ll keep = 0;
    for (int j = 0; j < n; j++) {
      if ((k2 | a.at(j)) == k2) keep += b.at(j);
    }
    ans = max(ans, keep);
  }
  
  cout << ans << '\n';
}