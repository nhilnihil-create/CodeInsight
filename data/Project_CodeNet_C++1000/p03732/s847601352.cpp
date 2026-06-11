#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
#define rem(i, m, n) for (int i = m; i >= n; --i)
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }

int dp[101][404][110];
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  rep(i, 0, N) cin >> w[i] >> v[i];
  int s = w.front() - 1;
  rep(i, 0, N) w[i] -= s;
  rep(i, 0, N) rep(j, 0, 400) rep(k, 0, N + 1) {
    chmax(dp[i + 1][j][k], dp[i][j][k]);
    chmax(dp[i + 1][j + w[i]][k + 1], dp[i][j][k] + v[i]);
  }
  int ans = 0;
  rep(i, 0, 400) rep(j, 0, N + 1) {
    if(i + (ll)j * s <= W) chmax(ans, dp[N][i][j]);
  }
  cout << ans << endl;
  return 0;
}
