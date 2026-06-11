#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmax(T &a, T b) { /* {{{ */
  if (a < b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int N, W;
int WS[105], VS[105];
int dp[105][105][305];

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    cin >> WS[i] >> VS[i];
  }
  for (int i = 0; i < 105; i++) {
    for (int j = 0; j < 105; j++) {
      for (int k = 0; k < 305; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < 305; k++) {
        if (dp[i][j][k] == -1) continue;
        int w = WS[i] - WS[0];
        chmax(dp[i + 1][j][k], dp[i][j][k]);
        chmax(dp[i + 1][j + 1][k + w], dp[i][j][k] + VS[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j < 305; j++) {
      long long w = (long long)WS[0] * i + j;
      if (w <= W) chmax(ans, dp[N][i][j]);
    }
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
