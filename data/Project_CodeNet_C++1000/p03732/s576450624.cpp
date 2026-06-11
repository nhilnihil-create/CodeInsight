#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define PRINTALL(V)                                                            \
  for (auto v : (V)) {                                                         \
    cerr << v << " ";                                                          \
  }                                                                            \
  cerr << "\n";
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
using namespace std;
template < class T > bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > using vec = std::vector< T >;
template < class T > void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF = 1061109567, INF2 = INF * INF;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int N, W;
  cin >> N >> W;
  vec< int > w(N), v(N);
  int baseweight;
  REP(i, N) {
    cin >> w[i] >> v[i];
    if (i == 0)
      baseweight = w[0];
    w[i] -= baseweight;
  }
 // PRINTALL(w);
  vec< vec< int > > dp(N + 1, vec< int >(3 * N + 1, -INF));
  //  REP(i, 3 * N + 1) { dp[0][i] = 0; }
  dp[0][0] = 0;
  REP(i, N) {
    REPR(j, N - 1) {
      REPR(k, 3 * N) {
        if (dp[j][k] != -INF) {
          if (k + w[i] <= 3 * N && j + 1 <= N)
            chmax(dp[j + 1][k + w[i]], dp[j][k] + v[i]);
        }
      }
    }
  }
  int ans = -INF;
  FORS(i, 0, N) {
    int wval = min(3 * N, W - baseweight * i);
    // DEBUG(i);
    // DEBUG(wval);
    // PRINTALL(dp[i]);
    FORS(j, 0, wval) { chmax(ans, dp[i][j]); }
  }
  print(ans);
}
// dpの向きによって複数個を許すかどうかが定まる、