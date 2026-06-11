#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e5+5;
const long long inf = (1LL<<60);

long long dp[nmax][3];
int a[nmax];
char op[nmax];
int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i != n) cin >> op[i + 1];
  }
  op[1] = '+';

  for (int i = 1; i <= n; i++) {
    dp[i][1] = dp[i][2] = dp[i][0] = -inf;
  }
  dp[1][0] = a[1];

  for (int i = 2; i <= n; i++) {
    if (op[i] == '+') {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
      dp[i][1] = dp[i - 1][1] - a[i];
      dp[i][2] = dp[i - 1][2] + a[i];
    } else {
      dp[i][1] = dp[i - 1][0] - a[i];
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
    }
  }

  return 0 * printf("%lld\n", max(max(dp[n][1], dp[n][2]), dp[n][0]));
}
