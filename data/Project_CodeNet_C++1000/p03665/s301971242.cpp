#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, p;
  cin >> n >> p;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll dp[51][2];
  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      dp[i + 1][0] = 2 * dp[i][0];
      dp[i + 1][1] = 2 * dp[i][1];
    } else {
      dp[i + 1][0] = dp[i][1] + dp[i][0];
      dp[i + 1][1] = dp[i][0] + dp[i][1];
    }
  }

  cout << dp[n][p] << endl;
}
