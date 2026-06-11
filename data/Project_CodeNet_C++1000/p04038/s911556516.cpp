#include <bits/stdc++.h>
using namespace std;
const int N = 2010, MOD = (int)(1e9 + 7);
int dp[N][N],n,k;
typedef long long ll;
ll power(ll a,int b) {
  ll ret = 1;
  while (b) {
    if (b&1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return ret;
}
ll jc[N * N],inv[N * N];
ll comb(int a,int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return 1ll * jc[a] * inv[b] % MOD * inv[a-b] % MOD;
}
int main() {
  scanf("%d%d",&n,&k);
  if (k == 1) return puts("1"), 0;
  jc[0] = 1;
  for (int i = 1 ; i <= n * k ; ++ i)
    jc[i] = 1ll * jc[i-1] * i % MOD;
  inv[n*k] = power(jc[n*k],MOD-2);
  for (int i = n*k-1 ; i >= 0 ; -- i)
    inv[i] = 1ll * inv[i+1] * (i+1) % MOD;
  dp[0][0] = 1;
  for (int i = 0 ; i <= n ; ++ i)
    for (int j = 0 ; j <= i ; ++ j) {
      (dp[i+1][j] += dp[i][j]) %= MOD;
      if (i > j) (dp[i][j+1] += 1ll * comb(n*k-j*k-(i-j)-1,k-2) * dp[i][j] % MOD) %= MOD;
    }
  printf("%lld\n",1ll * dp[n][n] * jc[n] % MOD);
  return 0;
}
