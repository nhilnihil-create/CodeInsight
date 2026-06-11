#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];

  map<int, int> mp;
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= t) continue;
    mp[i] = t = a[i];
  }
  
  sort(a.begin(), a.end());
  vector<lint> c(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    c[i] = c[i + 1] + a[i];
  }
  auto lsum = [&](lint b) {
    int i = upper_bound(a.begin(), a.end(), b) - a.begin();
    return c[i] - b * (n - i);
  };

  t = 0;
  for (int i = 0; i < n; i++) {
    if (mp.count(i)) {
      cout << lsum(t) - lsum(mp[i]) << '\n';
      t = mp[i];
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}