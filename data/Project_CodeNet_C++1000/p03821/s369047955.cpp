#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ll mod = (a[i] + ans) % b[i];
    if (mod == 0) continue;
    ll cnt = b[i] - mod;
    ans += cnt;
  }
  cout << ans << endl;
}
