#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int INFTY = 1e7+1;

int main() {
  int n, w; cin >> n >> w;
  Graph G(n, vi(2));
  rep(i,n) rep(j,2) cin >> G[i][j];
  int w1 = G[0][0] - 1;
  rep(i,n) G[i][0] -= w1;
  vector<Graph> dp(n+1, Graph(4*n, vi(n+1, -INFTY)));
  dp[0][0][0] = 0;
  rep(i,n) {
    rep(j,4*(i+1)) {
      if (j < G[i][0]) {
        dp[i+1][j] = dp[i][j];
        continue;
      }
      rep(k,i+1) {
        dp[i+1][j][k+1] = max(dp[i][j][k+1], dp[i][j-G[i][0]][k] + G[i][1]);
      }
    }
  }
  int ans = 0;
  rep(k,n+1) {
    if (w1 * k > w) break;
    int accept = min(4*n, w+1-w1*k);
    rep(j,accept) ans = max(ans, dp[n][j][k]);
  }
  cout << ans << endl;
  return 0;
}
