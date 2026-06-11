#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int n, ma, mb;
int a[43], b[43], c[43];
int dp[443][443];
int ans = INF;

int main(int argc, char const *argv[]) {
  cin >> n >> ma >> mb;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }

  memset(dp, INF, sizeof(dp));

  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 400; j >= a[i]; --j) {
      for (int k = 400; k >= b[i]; --k) {
        dp[j][k] = min(dp[j][k], dp[j - a[i]][k - b[i]] + c[i]);
      }
    }
  }

  for (int i = 1; i * max(ma, mb) <= 400; ++i) {
    ans = min(ans, dp[i * ma][i * mb]);
  }

  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}