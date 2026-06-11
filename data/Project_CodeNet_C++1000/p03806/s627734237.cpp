#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

ll dp[60][510][510];

int main() {
  ll n, ma, mb;
  cin >> n >> ma >> mb;
  vector<ll> a(n), b(n), c(n);
  REP(i, n) cin >> a[i] >> b[i] >> c[i];

  REP(i, 50) REP(j, 500) REP(k, 500) { dp[i][j][k] = INF; }

  dp[0][0][0] = 0;
  REP(i, n) REP(j, 500) REP(k, 500) {
    if (dp[i][j][k] >= INF) continue;
    chmin(dp[i + 1][j][k], dp[i][j][k]);
    chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
  }

  ll ans = INF;
  FOR(j, 1, 500) FOR(k, 1, 500) {
    if (j * mb == k * ma) {
      chmin(ans, dp[n][j][k]);
    }
  }
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}