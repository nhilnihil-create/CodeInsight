// 2020-08-24 20:31:42
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
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

const int inf = 1e9;
void answer() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
  vector<vector<int> > dp(410, vector<int>(410, inf));
  dp[0][0] = 0;
  rep(i, n) {
    vector<vector<int> > p = dp;
    int mx = 10 * (i+1);
    REPC(aj, 1, mx) REPC(bj, 1, mx) {
      if(aj - a[i] >= 0 && bj - b[i] >= 0) {
        chmin(dp[aj][bj], p[aj - a[i]][bj - b[i]] + c[i]);
      }
    }
  }
  int ans = inf;
  REPC(aj, 1, 400) {
    if(aj % ma == 0) {
      int bj = aj / ma * mb;
      if(1 <= bj && bj <= 400) {
        chmin(ans, dp[aj][bj]);
      }
    }
  }
  if(ans == inf) ans = -1;
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}