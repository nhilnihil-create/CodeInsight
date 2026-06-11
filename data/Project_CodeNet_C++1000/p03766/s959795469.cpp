#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

typedef long long ll;

const int MOD = 1000000007;
const int N_MAX = 1000000;

ll n;
int dp[N_MAX];
int acc[N_MAX + 1];

void solve() {
  dp[0] = 1; acc[0] = 1;
  dp[1] = n; acc[1] = n + 1;

  FOR(i, 2, n) {
    dp[i] = (dp[i- 1] + (n - 1) * n % MOD) % MOD;
    if (i >= 3) {
      dp[i] = (dp[i] - (i - 2) + acc[i - 3]) % MOD;
    }
    acc[i] = (acc[i - 1] + dp[i]) % MOD;
  }
  printf("%d\n", dp[n]);
}

void input() {
  scanf("%lld", &n);
}

int main() {
  input();
  solve();
  return 0;
}
