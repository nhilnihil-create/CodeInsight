#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr int INF = 0x3f3f3f3f;

int a[44], b[44], c[44];
int dp[44][444][444];
int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  rep(i, 0, n) cin >> a[i] >> b[i] >> c[i];
  rep(i, 0, 44) rep(j, 0, 444) rep(k, 0, 444) dp[i][j][k] = INF;

  dp[0][0][0] = 0;
  rep(i, 0, n) {
    rep(j, 0, 401) {
      rep(k, 0, 401) {
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        dp[i + 1][j + a[i]][k + b[i]] =
          min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
      }
    }
  }

  int i = 1;
  int ans = INF;
  while (ma * i < 401 && mb * i < 401) {
    ans = min(ans, dp[n][ma * i][mb * i]);
    ++i;
  }
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
  cout << endl;
  return 0;
}