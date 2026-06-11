#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N, P;
  cin >> N >> P;

  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(2, 0));
  dp[0][0] = 1;
  rep(i, N) {
    int a;
    cin >> a;
    rep(j, 2) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][(j + a) % 2] += dp[i][j];
    }
  }
  cout << dp[N][P] << endl;

  return 0;
}