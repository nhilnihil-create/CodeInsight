#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n;
  cin >> n;
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  V<ll> s(n);
  s[0] = a[0];
  for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];

  auto can_live = [&](int k) {
    bool ret = true;
    ll size = s[k];
    for (int i = k + 1; i < n; i++) {
      if (a[i] <= 2 * size) {
        size += a[i];
      } else {
        ret = false;
        break;
      }
    }
    return ret;
  };

  int l(0), r(n - 1);
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (can_live(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  int ans = n - l - 1;
  if (can_live(l)) ans++;
  cout << ans << endl;
}
