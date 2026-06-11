#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll ans = 1e18;
  for (int i = 0; i < 1 << n; ++i) {
    vector<ll> aa = a;
    ll ma = aa[0];
    int cnt = 0;
    ll sum = 0;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
	if (j > 0 && aa[j] <= ma) {
	  ll need = ma - aa[j] + 1;
	  sum += need;
	  aa[j] += need;
	}
      }
      if (j == 0 || aa[j] > ma) cnt++;
      ma = max(ma, aa[j]);
    }
    if (cnt >= k) ans = min(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}
