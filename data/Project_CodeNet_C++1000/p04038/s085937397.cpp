#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 2010;
const int mod = 1e9 + 7;
using namespace std;

inline ll mul(ll a,ll b) { return 1ll * a * b % mod; }

ll dp[maxn][maxn], fac[4000005], ifac[4000005];
int n, m, i, j, k, K;

inline ll qpow(ll a,int b,int p = mod) {
  ll res = 1;
  while(b) {
    if(b & 1) (res *= a) %= p;
    (a *= a) %= p;  b >>= 1;  
  }
  return res;
}

inline void pre_work(int N) {
  fac[0] = 1;
  for(int i = 1;i <= N;i++) fac[i] = (fac[i - 1] * i) % mod;
  ifac[N] = qpow(fac[N],mod - 2);
  //printf("%lld\n",ifac[N]);
  for(int i = N - 1;~i;i--) ifac[i] = (ifac[i + 1] * (i + 1)) % mod;
}

inline ll C(int n,int m) { return (((fac[m] * ifac[n]) % mod) * ifac[m - n]) % mod; }

int main()  {
  scanf("%d %d",&n,&K);  if(K == 1) return 0 & puts("1");
  dp[0][0] = 1;
  pre_work(4000000);
  for(int i = 1;i <= n;i++) {
      for(int j = 0;j <= i;j++) {
      dp[i][j] = dp[i - 1][j];  if(j == 0) continue;  int qwq;
      (dp[i][j] += dp[i][j - 1] * (n - j + 1) % mod * C(K - 2,n - i + (n - j + 1) * (K - 1) - 1) % mod) %= mod;
    }
  }
  printf("%lld\n",dp[n][n]);
  return 0;
}