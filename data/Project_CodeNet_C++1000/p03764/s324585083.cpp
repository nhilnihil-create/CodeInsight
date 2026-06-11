#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int emod(long long x, long long p = mod) {
  return (x % p + p) % p;
}
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<long long> x(n); for (int i = 0; i < n; i++) cin >> x[i];
  vector<long long> y(m); for (int i = 0; i < m; i++) cin >> y[i];
  long long sumx = 0, sumy = 0;
  for (int i = 1; i < n; i++) {
    sumx = (sumx + (x[i] - x[i - 1]) * i % mod * (n - i) % mod) % mod;
  }
  for (int i = 1; i < m; i++) {
    sumy = (sumy + (y[i] - y[i - 1]) * i % mod * (m - i) % mod) % mod;
  }
  cout << emod(sumx * sumy) << '\n';
  return 0;
}