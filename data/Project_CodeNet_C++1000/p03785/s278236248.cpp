#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll n, c, k;
  cin >> n >> c >> k;
  vector<ll> t(n + 1);
  for (int i = 0; i < n; i++) cin >> t[i];
  t[n] = 3 * 1e9;
  sort(t.begin(), t.end());

  ll ans = 0;
  ll first = t[0];
  ll num = 1;
  for (int i = 1; i <= n; i++) {
    num++;
    if (num > c || t[i] - first > k) {
      num = 1;
      first = t[i];
      ans++;
    }
  }
  cout << ans << endl;
}
