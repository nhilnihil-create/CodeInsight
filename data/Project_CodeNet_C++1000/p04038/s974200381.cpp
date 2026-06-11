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

const int N_MAX = 2003;
int dp[N_MAX][N_MAX];

const int mod = 1e9 + 7;
int power(int x, int y) {
  int ret = 1;
  while (y > 0) {
    if ((y & 1) == 1)
      ret = 1ll * x * ret % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return ret;
}

const int M_MAX = 4000003;
int fac[M_MAX], iFac[M_MAX];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k == 1) {
    printf("1\n");
    return 0;
  }
  int m = n * k;
  fac[0] = 1;
  for (int i = 1; i <= m; ++i)
    fac[i] = 1ll * i * fac[i - 1] % mod;
  iFac[m] = power(fac[m], mod - 2);
  for (int i = m; i > 0; --i)
    iFac[i - 1] = 1ll * i * iFac[i] % mod;
  
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1ll * fac[i * (k - 1) - 1] * iFac[k - 2] % mod *
      iFac[(i - 1) * (k - 1)] % mod * dp[i - 1][0] % mod;
    for (int j = 1; j <= i; ++j)
      dp[i][j] = (1ll * fac[i * (k - 1) + j - 1] * iFac[k - 2] % mod *
                  iFac[(i - 1) * (k - 1) + j] % mod * dp[i - 1][j] +
                  dp[i][j - 1]) % mod;
  }
  printf("%lld\n", 1ll * dp[n][n] * fac[n] % mod);
  return 0;
}
