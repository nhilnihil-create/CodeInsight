#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll dp[55][2505][55];

int main() {
  ll n, a, tmp, ans = 0, cnt;
  cin >> n >> a;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  dp[0][0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n * a; ++j) {
      for (int k = 0; k < n; ++k) {
        dp[i + 1][j][k] += dp[i][j][k];
        dp[i + 1][j + x[i]][k + 1] += dp[i][j][k];
      }
    }
  }

  for (int i = 1; i <= n; ++i) ans += dp[n][i * a][i];

  cout << ans << endl;
  return 0;
}