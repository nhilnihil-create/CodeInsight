#include <bits/stdc++.h>
#define reg register
#define int long long
using namespace std;
const int MAXN = 310;
const int MAXM = 8010;
int n, A, dp[MAXN][MAXM];
inline void work() {
  scanf("%lld%lld", &n, &A), dp[0][0] = 1;
  for(reg int i = 1; i <= n; ++i) {
    int x;
    scanf("%lld", &x);
    for(reg int j = i; j > 0; j--) for(reg int k = A * n; k >= x; k--) dp[j][k] += dp[j - 1][k - x];
  }
  int ans = 0;
  for(reg int i = 1; i <= n; ++i) ans += dp[i][i * A];
  printf("%lld\n", ans);
}
signed main() {
  int _ = 1;
  // scanf("%d", &_);
  while(_--) work();
  return 0;
}
