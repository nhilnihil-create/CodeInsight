#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7, inv2 = 500000004;
int dp[5050][5050];

int main() {
  int N;
  string s;

  cin >> N >> s;

  dp[0][0] = 1;

  for (int i = 0; i < N; ++i) {
    (dp[i + 1][1] += 2 * dp[i][0] % mod) %= mod;
    (dp[i + 1][0] += dp[i][0]) %= mod;
    for (int j = 1; j < N; ++j) {
      (dp[i + 1][j + 1] += 2 * dp[i][j] % mod) %= mod;
      (dp[i + 1][max(0, j - 1)] += dp[i][j]) %= mod;
    }
  }

  int64_t ans = dp[N][s.size()];
  for (int i = 0; i < s.size(); ++i) {
    (ans *= inv2) %= mod;
  }

  cout << ans << endl;
}
