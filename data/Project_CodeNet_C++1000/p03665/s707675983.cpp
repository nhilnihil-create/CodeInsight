#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
#define int long long

const int N = 55;
const int MAXV = 105;
int dp[N][N * MAXV];

signed main() {
  int n, p;
  cin >> n >> p;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  dp[0][0] = 1LL;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N * MAXV; j++) {
      if(j - a[i] >= 0) {
        dp[i][j] += dp[i - 1][j - a[i]];
      }
      dp[i][j] += dp[i - 1][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < N * MAXV; i++) {
    if(i % 2 == p % 2) ans += dp[n][i];
  }

  cout << ans << '\n';
}

