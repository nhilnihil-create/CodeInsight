#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
signed main() {
  int n;
  cin >> n;
  vector<int> t(n), a(n);
  vector<bool> one(n, false);
  one[0] = one[n - 1] = true;
  for (auto&& w : t) cin >> w;
  for (auto&& w : a) cin >> w;
  bool flg = true;
  if (t[0] > a[0]) flg = false;
  if (t[n - 1] < a[n - 1]) flg = false;

  for (int i = 0; i < n - 1; i++) {
    if (t[i + 1] < t[i]) flg = false;
    if (t[i + 1] > t[i]) {
      one[i + 1] = true;
      if (t[i + 1] > a[i + 1]) flg = false;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i - 1] < a[i]) flg = false;
    if (a[i - 1] > a[i]) {
      one[i - 1] = true;
      if (t[i - 1] < a[i - 1]) flg = false;
    }
  }
  if (!flg) cout << 0 << endl, exit(0);
  int ans = 1;

  for (int i = 0; i < n; i++) {
    if (one[i]) continue;
    (ans *= min(t[i], a[i])) %= mod;
  }
  cout << ans << endl;
}