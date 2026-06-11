#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> x(n), y(m);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> y[i];
  }
  ll xs = 0, ys = 0;
  for (int i = 1; i < n; i++) {
    xs += ((x[i] - x[i-1]) * (1ll * i * (n - i) % MOD)) % MOD;
    xs %= MOD;
  }
  for (int i = 1; i < m; i++) {
    ys += ((y[i] - y[i-1]) * (1ll * i * (m - i) % MOD)) % MOD;
    ys %= MOD;
  }
  ll res = (xs * ys) % MOD;
  cout << res << endl;
  return 0;
}
