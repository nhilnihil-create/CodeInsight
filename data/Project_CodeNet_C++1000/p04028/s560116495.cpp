#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = s.size();

  constexpr int kMod = 1'000'000'000 + 7;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] == 0) continue;
      (dp[i + 1][max(j - 1, 0)] += dp[i][j]) >= kMod ? dp[i + 1][max(j - 1, 0)] -= kMod : 0;
      (dp[i + 1][j + 1] += 2 * dp[i][j] % kMod) >= kMod ? dp[i + 1][j + 1] -= kMod : 0;
    }
  }
  const int kInv = (kMod + 1) / 2;
  int res = dp[n][m];
  for (int i = 0; i < m; ++i) res = 1LL * res * kInv % kMod;
  cout << res << "\n";
}
