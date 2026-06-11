#include <bits/stdc++.h>
using namespace std;

static const int Maxn = 100005;

int n, st, ed;
char op[Maxn];
long long a[Maxn];
long long dp[Maxn][3];

int main() {
  scanf("%d\n", &n);
  scanf("%lld ", a + 1), op[1] = '+';
  for (int i = 2; i <= n; ++i)
    scanf("%c %lld ", op + i, a + i);
  memset(dp, -63, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][2] = dp[i - 1][2] + a[i];
    if (op[i] == '-') {
      dp[i][1] = max(dp[i - 1][0] - a[i], dp[i - 1][1] + a[i]);
      dp[i][2] = max(dp[i][2], dp[i - 1][1] + a[i]);
    }
    else {
      dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
      dp[i][1] = max(dp[i - 1][2] + a[i], dp[i - 1][1] - a[i]);
    }
  }
  printf("%lld\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
  return 0;
}