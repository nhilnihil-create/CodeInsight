#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define MOD 1000000007

signed main() {
  int n, m;
  cin >> n >> m;
  int x[n + 1], y[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> y[i];
  }
  int xsum = 0, ysum = 0;
  for (int i = 1; i <= n; i++) {
    xsum += (i - 1) * x[i] - (n - i) * x[i];
    xsum %= MOD;
  }
  for (int i = 1; i <= m; i++) {
    ysum += (i - 1) * y[i] - (m - i) * y[i];
    ysum %= MOD;
  }
  cout << (xsum * ysum) % MOD << endl;
  return 0;
}
