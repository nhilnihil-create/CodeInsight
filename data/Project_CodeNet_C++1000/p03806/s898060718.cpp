#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, ma, mb;
  cin >> n >> ma >> mb;
  vl a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
  ll dp[n + 1][401][401] = {};
  rep(i, n + 1) rep(j, 401) rep(k, 401) dp[i][j][k] = 1e18;
  dp[0][0][0] = 0;
  rep(i, n) rep(j, 401) rep(k, 401) {
    if(dp[i][j][k] == 1e18) continue;
    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
    ll nj = j + a[i];
    ll nk = k + b[i];
    dp[i + 1][nj][nk] = min(dp[i + 1][nj][nk], dp[i][j][k] + c[i]);
  }
  ll ans = 1e18;
  rep2(j, 1, 401) rep2(k, 1, 401) if(mb * j == ma * k) ans =
      min(ans, dp[n][j][k]);
  cout << (ans == 1e18 ? -1 : ans) << endl;
}