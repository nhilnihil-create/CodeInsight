#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  map<ll, int> m;
  for (int i = 0; i < n; i++) {
    if (m.count(a[i]) == 0) m[a[i]] = 0;
    m[a[i]]++;
  }

  ll ans(0);
  for (auto e : m)
    if (e.second % 2 != 0) ans++;

  cout << ans << endl;
}
