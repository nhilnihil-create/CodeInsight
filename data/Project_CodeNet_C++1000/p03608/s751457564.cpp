// 2020-08-29 17:20:16
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, ll>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
const int V = 210;
const ll inf = 1e12;
ll d[V][V];
void answer() {
  int n, m, rz;
  cin >> n >> m >> rz;
  vector<int> r(rz);
  rep(i, rz) {
    cin >> r[i];
    r[i]--;
  }
  rep(i, n) rep(j, n) {
    d[i][j] = inf;
    if (i == j) d[i][j] = 0;
  }
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = c;
    d[b][a] = c;
  }
  rep(k, n) rep(i, n) rep(j, n) { chmin(d[i][j], d[i][k] + d[k][j]); }
  ll ans = inf;
  sort(ALL(r));
  do {
    ll now = 0;
    rep(i, rz - 1) now += d[r[i]][r[i + 1]];
    chmin(ans, now);
  } while (next_permutation(ALL(r)));
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}