// by newbiechd
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

// DELETE the debugging information!
#define debug(x) std::cerr << #x << " = " << (x) << std::endl

const int N_MAX = 100003;
int a[N_MAX];
long long dp[N_MAX][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  dp[0][1] = -1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = std::max(dp[i - 1][0] + a[i] / 2, dp[i - 1][1] + (a[i] + 1) / 2);
    dp[i][1] = std::max(dp[i - 1][0] + (a[i] - 1) / 2, dp[i - 1][1] + a[i] / 2);
    if (a[i] == 0)
      dp[i][1] = -1;
  }
  printf("%lld\n", std::max(dp[n][0], dp[n][1]));
  return 0;
}
