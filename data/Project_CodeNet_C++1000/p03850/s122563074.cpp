#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP2D(a, n, m) REP(i, n) REP(j, m) printf("%lld%c", a[i][j], j + 1 == m ? '\n' : ' '); puts("")

typedef long long ll;

const int N_MAX = 100000;
const ll INF = 1e15;

int N;
int A[N_MAX];
int op[N_MAX + 1];
ll dp[N_MAX + 1][3];

void solve() {
  fill(dp[0], dp[N + 1], -INF);
  fill(dp[0], dp[1], 0);
  int m = 1;
  REP(i, N) {
    REP(j, min(m, 3)) {
      int a = A[i] * ((j + op[i]) % 2 == 0 ? 1 : -1);
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a);
      if (j < 2 && op[i] > 0) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a);
      }
      if (j > 0) {
        dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + a);
      }
    }
    m += op[i];
  }

  // DUMP2D(dp, N + 1, 3);

  ll ans = -INF;
  REP(j, 3) ans = max(ans, dp[N][j]);
  printf("%lld\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", A + i);
    if (i + 1 < N) {
      char buf[2];
      scanf("%s", buf);
      op[i + 1] = buf[0] == '-' ? 1 : 0;
    }
  }
}

int main() {
  input();
  solve();
  return 0;
}
