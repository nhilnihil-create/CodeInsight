#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main() {
  int n;
  cin >> n;
  int s[n];
  rep(i, n) cin >> s[i];
  ll dp[n + 1][10010];
  rep(j, n + 1) rep(i, 10010) dp[j][i] = 0;
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 10010) {
      if (dp[i][j] == 1) dp[i + 1][j] = 1;
      if (j - s[i] < 0 || dp[i][j - s[i]] == 0) continue;
      dp[i + 1][j] = 1;
    }
  }
  ll mx_val = 0;
  rep(i, 10005) {
    ll val = dp[n][i];
    if (val == 0 || i % 10 == 0) continue;
    mx_val = MAX(mx_val, i);
  }
  cout << mx_val << endl;
  return 0;
}