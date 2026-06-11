#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9 + 7;

signed main() {
  int n;
  cin >> n;
  char s[n][2];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j)
      cin >> s[j][i];
  }
  vector < int64_t > dp(n, 1);
  for (int i = 0; i < n; ++i) {
    if (s[i][0] == s[i][1]) {
      if (i && s[i - 1][0] == s[i - 1][1])
        dp[i] = (dp[i - 1] * 2) % mod;
      else if (i) 
        dp[i] = dp[i - 1];
      else
        dp[i] = 3;
    }
    else {
      if (i >= 2 && s[i - 2][0] == s[i - 2][1])
        dp[i] = (dp[i - 2] * 2) % mod;
      else if (i >= 2)
        dp[i] = (dp[i - 2] * 3) % mod;
      else
        dp[i] = 6;
    }
  }
  cout << dp[n - 1] << '\n';
}