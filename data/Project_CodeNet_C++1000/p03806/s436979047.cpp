#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <complex>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int dp[41][401][401];

int main(void) {

  int n, a[40], b[40], c[40], ma, mb;
  cin >> n >> ma >> mb;
  rep(i, n) cin >> a[i] >> b[i] >> c[i];

  int A = 0, B = 0;
  rep(i, n) A += a[i], B += b[i];

  int k = min(A/ma, B/mb);

  rep(i, k*ma + 1) rep(j, k*mb + 1) dp[0][i][j] = INT_MAX;
  dp[0][0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int x = 0; x <= k*ma; x++) {
      for (int y = 0; y <= k*mb; y++) {
	dp[i][x][y] = dp[i-1][x][y];
	if (x >= a[i-1] && y >= b[i-1] && dp[i-1][x-a[i-1]][y-b[i-1]] != INT_MAX) {
	  dp[i][x][y] = min(dp[i][x][y], dp[i-1][x-a[i-1]][y-b[i-1]] + c[i-1]);
	}
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 1; i <= k; i++) {
    ans = min(ans, dp[n][i*ma][i*mb]);
  }

  if (ans == INT_MAX) cout << -1 << endl;
  else cout << ans << endl;

  return 0;

}
