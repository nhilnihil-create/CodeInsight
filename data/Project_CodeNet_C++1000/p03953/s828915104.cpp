#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int m;
  long long k;
  cin >> m >> k;
  vector<int> pm(n - 1);
  iota(pm.begin(), pm.end(), 0);
  for (int i = 0; i < m; i++) {
    int z;
    cin >> z;
    z--;
    swap(pm[z - 1], pm[z]);
  }
  vector<int> res(n - 1);
  iota(res.begin(), res.end(), 0);
  auto trans = [&](vector<int> f, vector<int> g) {
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
      a[i] = f[g[i]];
    }
    return a;
  };
  while (k) {
    if (k & 1) {
      res = trans(res, pm);
    }
    pm = trans(pm, pm);
    k >>= 1;
  }
  long long cur = x[0];
  cout << cur << '\n';
  for (int i = 0; i < n - 1; i++) {
    int d = x[res[i] + 1] - x[res[i]];
    cur += d;
    cout << cur << '\n';
  }
  return 0;
}
