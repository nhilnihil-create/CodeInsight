#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  ll n, w;
  cin >> n >> w;
  vector<pair<ll, ll>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;

  ll m = p[0].first;
  if (w < m) cout << 0 << endl;
  else if (w >= (m + 3) * n - 3) {
    ll ans = 0;
    rep(i, n) ans += p[i].second;
    cout << ans << endl;
  }
  else {
    rep(i, n) p[i].first -= m;
    vector<vector<ll>> dp(3 * n - 2, vector<ll>(n + 1, 0));
    rep(i, n) {
      repr(j, 3 * n - 3) {
        if (j - p[i].first < 0) continue;
        repr(k, i) {
          dp[j][k + 1] = max(dp[j][k + 1], dp[j - p[i].first][k] + p[i].second);
        }
      }
    }

    ll ans = 0;
    rep(j, 3 * n - 2) {
      rep(k, n + 1) {
        if (w < j + k * m) continue;
        ans = max(ans, dp[j][k]);
      }
    }
    cout << ans << endl;
  }



 
  return 0;
}
