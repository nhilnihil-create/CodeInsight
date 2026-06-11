#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP2D(a, n, m) REP(i, n) REP(j, m) printf("%lld%c", a[i][j], j + 1 == m ? '\n' : ' '); puts("")

typedef long long ll;

//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

ll mod_inverse(ll x, ll mod) {
  return mod_pow(x, mod - 2, mod);
}

//------------------------------------------------------------------------------
const int N_MAX = 5000;
const int MOD = 1e9+7;

int N;
char s[N_MAX + 1];

int M;
ll dp[N_MAX + 1][N_MAX + 1];

void solve() {
  dp[0][0] = 1;
  REP(i, N) FOR(j, 0, N) {
    // printf("i: %d, j: %d, k: %d\n", i, j, k);
    int j1 = max(j - 1, 0);
    dp[i + 1][j1] = (dp[i + 1][j1] + dp[i][j]) % MOD;         // BS
    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;   // 0
    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;   // 1
  }

  // DUMP2D(dp, N + 1, N + 1);

  ll b = mod_pow(2, M, MOD);
  ll ans = dp[N][M] * mod_inverse(b, MOD) % MOD;
  printf("%lld\n", ans);
}


void input() {
  scanf("%d", &N);
  scanf("%s", s);
  M = strlen(s);
}

int main() {
  input();
  solve();
  return 0;
}
