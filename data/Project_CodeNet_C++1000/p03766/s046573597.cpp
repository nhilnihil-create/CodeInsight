#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, MOD = 1e9 + 7;
typedef long long ll;
ll dp[N],sum;
int n;
int main() {
  scanf("%d",&n);
  dp[0] = 1;
  dp[1] = n;
  sum = 2 * n;
  for (int i = 2 ; i <= n ; ++ i) {
    dp[i] = 1ll * (n - 1) * (n - 1) % MOD;
    (dp[i] += sum - dp[i-2]) %= MOD;
    (sum += dp[i]) %= MOD;
    if (i - n >= 0) (sum -= dp[i-n]) %= MOD;
    else (sum -= 1) %= MOD;
  }
  printf("%lld\n",(dp[n] + MOD) % MOD);
  return 0;
}