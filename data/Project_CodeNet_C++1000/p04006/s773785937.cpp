#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long n, x, a[2005], dp[2005][2005], sum, ans = inf;
int main() {
  scanf("%lld%lld", &n, &x);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = a[i];
    for (int j = 1; j < n; j++) {
      int k = i - j;
      if (k <= 0) k += n;
      dp[i][j] = min(dp[i][j - 1], a[k]);
    }
  }
  for (int i = 0; i < n; i++) {
    sum = x * i;
    for (int j = 1; j <= n; j++) sum += dp[j][i];
    ans = min(ans, sum);
  }
  printf("%lld", ans);
  return 0;
}
