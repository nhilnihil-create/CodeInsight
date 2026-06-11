#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

signed main() {
  int n;
  cin >> n;
  map < int, int > cnt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  bool ok = 1;
  for (int i = n - 1; i >= 0; i -= 2) {
    if (i == 2)
      ok = ok && (cnt[i] == 2);
    else if (!i)
      ok = ok && (cnt[i] == 1);
    else
      ok = ok && (cnt[i] == 2);
  }
  if (!ok)
    cout << "0\n";
  else {
    int64_t ans = 1;
    for (int i = 0; i < n / 2; ++i)
      (ans *= 2) %= mod;
    cout << ans << '\n';
  }
}