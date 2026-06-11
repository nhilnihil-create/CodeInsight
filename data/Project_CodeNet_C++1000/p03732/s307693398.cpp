#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;

const ll INF = 1LL << 32;

int main() {
  ll N, w;

  cin >> N >> w;

  vll ws(N);
  vll vs(N);
  ll w0;
  cin >> w0 >> vs[0];
  ws[0] = 0;
  for (ll i = 1; i < N; i++) {
    cin >> ws[i] >> vs[i];
    ws[i] -= w0;
  }

  ll ans = 0;
  for (ll n = 0; n <= N; n++) {
    ll wp = w - n * w0;
    if (wp < 0) continue;
    if (wp > 3 * n) {
      vvll dp(N + 1, vll(n + 1, 0));
      for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j <= n; j++) {
          if (i < j) continue;
          dp[i][j] = dp[i - 1][j];
          if (j >= 1) chmax(dp[i][j], dp[i - 1][j - 1] + vs[i - 1]);
        }  // j
      }    // i
      chmax(ans, dp[N][n]);
    } else {
      vector<vvll> dp(N + 1, vvll(wp + 1, vll(n + 1, 0)));
      for (ll i = 1; i <= N; i++) {
        for (ll k = 0; k <= wp; k++) {
          for (ll j = 0; j <= n; j++) {
            if (i < j) continue;
            dp[i][k][j] = dp[i - 1][k][j];
            if (j >= 1 && k >= ws[i - 1])
              chmax(dp[i][k][j], dp[i - 1][k - ws[i - 1]][j - 1] + vs[i - 1]);
          }  // j
        }    // k
      }      // i
      chmax(ans, dp[N][wp][n]);
    }
  }

  cout << ans << endl;

  return 0;
}
