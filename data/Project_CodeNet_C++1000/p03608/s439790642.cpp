#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const int MX = 201;

int main() {
  ll n, m, R, a, b, c;
  cin >> n >> m >> R;
  vector<ll> r(R);
  rep(i, R) cin >> r[i], r[i]--;

  ll dp[MX][MX];
  rep(i, MX) rep(j, MX) dp[i][j] = (i == j ? 0 : (ll)1e15);

  rep(i, m) {
    cin >> a >> b >> c;
    a--, b--;
    dp[a][b] = dp[b][a] = c;
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

  ll ans = 1e9;
  sort(r.begin(), r.end());
  do {
    ll t = 0;
    rep(i, R - 1) t += dp[r[i]][r[i + 1]];
    ans = min(ans, t);
    cout << endl;
  } while (next_permutation(r.begin(), r.end()));

  cout << ans << endl;
  return 0;
}