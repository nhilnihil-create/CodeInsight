#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int ADD(int x, int y) {
  int res = x + y;
  if (res >= MOD) res -= MOD;
  return res;
}

int MUL(int x, int y) {
  return 1ll * x * y % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<int>> dp(2, vector<int>(n + s.size() + 6, 0));
  dp[n & 1][s.size()] = 1;

  for (int i = n - 1; i >= 0; i--) {
    fill(begin(dp[i & 1]), end(dp[i & 1]), 0);
    for (int j = 0; j < n + s.size() + 5; j++) {
      dp[i & 1][j + 1] = ADD(dp[i & 1][j + 1], MUL(2, dp[(i + 1) & 1][j]));
      dp[i & 1][max(0, j - 1)] = ADD(dp[i & 1][max(0, j - 1)], dp[(i + 1) & 1][j]);
    }
  }

  cout << dp[0][0] << "\n";
  return 0;
}
