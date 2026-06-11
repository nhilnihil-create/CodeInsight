#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

ll dp[51][51][2501];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a;
  cin >> n >> a;
  vector<ll> x(n);
  rep(i, 0, n) cin >> x[i];


  dp[0][0][0] = 1;
  rep(j, 0, n) {
    rep(k, 0, n) {
      rep(s, 0, 2501) {
        if (dp[j][k][s] == 0)
          continue;
        dp[j + 1][k][s] += dp[j][k][s];
        dp[j + 1][k + 1][s + x[j]] += dp[j][k][s];
      }
    }
  }

  ll ans = 0;
  rep(k, 1, n + 1) ans += dp[n][k][k * a];
  cout << ans << endl;
}
