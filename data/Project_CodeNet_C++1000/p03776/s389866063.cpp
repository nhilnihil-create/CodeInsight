#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  ll value[n];
  rep (i,n) cin >> value[i];

  P dp[n][n+1];  // [from 1~i][select some] <max value, ways>
  rep (i,n) rep (j,n+1) dp[i][j] = P(0,1);
  dp[0][1] = P(value[0],1);

  for (int i=1; i<n; i++) {
    for (int j=1; j<i+2; j++) {
      if (dp[i-1][j-1].first + value[i] == dp[i-1][j].first) {
        dp[i][j].first = dp[i-1][j].first;
        dp[i][j].second = dp[i-1][j-1].second + dp[i-1][j].second;  // sum ways
      }
      else if (dp[i-1][j-1].first + value[i] > dp[i-1][j].first) {
        dp[i][j].first = dp[i-1][j-1].first + value[i];
        dp[i][j].second = dp[i-1][j-1].second;
      }
      else {
        dp[i][j].first = dp[i-1][j].first;
        dp[i][j].second = dp[i-1][j].second;
      }
    }
  }

  ll ans[3] = {0,0,a};  // <value, ways, selection>

  for (int i=a; i<=b; i++) {
    if (ans[0] * i < dp[n-1][i].first * ans[2]) {
      ans[0] = dp[n-1][i].first;
      ans[1] = dp[n-1][i].second;
      ans[2] = i;
    }
    else if (ans[0] * i == dp[n-1][i].first * ans[2]) {
      ans[1] += dp[n-1][i].second;
    }
  }

  long double x = ans[0] / (long double)ans[2];
  printf("%.6Lf\n", x);
  cout << ans[1] << endl;
  return 0;
}
