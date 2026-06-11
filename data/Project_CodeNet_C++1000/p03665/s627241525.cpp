#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;
template <typename T = long long>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<ll>> dp(n, vector<ll>(2, 0));
  dp[0][0] = 1;
  dp[0][a[0] % 2] += 1;
  for (int i = 1; i < n; i++) {
    if (a[i] % 2 == 0) {
      dp[i][0] = dp[i - 1][0] * 2;
      dp[i][1] = dp[i - 1][1] * 2;
    } else {
      dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
      dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
    }
  }
  cout << dp[n - 1][p] << endl;
}
