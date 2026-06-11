#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll ans = 1e18;
  for (int i = 0; i < 1 << n; ++i) {
    if (i >> 0 & 1) continue;
    ll ma = a[0];
    vector<ll> tmp = a;
    for (int j = 1; j < n; ++j) {
      if ((i >> j & 1) && a[j] <= ma) {
	tmp[j] += ma - a[j] + 1;
      }
      ma = max(ma, tmp[j]);
    }

    int cnt = 1;
    ll cost = 0;
    ma = a[0];
    for (int j = 1; j < n; ++j) {
      if (tmp[j] > ma) {
	cnt++;
	ma = tmp[j];
      }
      cost += tmp[j] - a[j];
    }
    if (cnt >= k) ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
