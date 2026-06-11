#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int dp[50][1000 + 100][1000 + 100];
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> a(N), b(N), c(N);
  REP(i, N) cin >> a[i] >> b[i] >> c[i];
  REP(i, 50) REP(j, 1000) REP(k, 1000) {
    dp[i][j][k] = INF;
    if (j == 0 && k == 0) dp[i][j][k] = 0;
  }
  REP(i, N) {
    REP(j, 1000) REP(k, 1000) {
      chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
      chmin(dp[i + 1][j][k], dp[i][j][k]);
    }
    int A = 10;
  }
  int ans = INF;
  for (int i = 1; i * Ma <= 800 && i * Mb <= 800; i++) {
    chmin(ans, dp[N][i * Ma][i * Mb]);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
}