# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui32 = unsigned int;
constexpr ll INFLL = 1e18;

#define CHECK_IMPL1(cond)              \
if (!(cond)) {                         \
    DEBUG("expected cond: " << #cond); \
    assert(cond);                      \
}

#define CHECK_IMPL2(cond, message)                                            \
if (!(cond)) {                                                                \
    DEBUG("expected cond: " << #cond << " failed with message: " << message); \
    assert(cond);                                                             \
}
#define CHECK_IMPL(_1, _2, NAME, ...) NAME
#define CHECK(...) CHECK_IMPL(__VA_ARGS__, CHECK_IMPL2, CHECK_IMPL1, CHECK_IMPL0)(__VA_ARGS__)

#ifdef __APPLE__
#define DEBUG(message) std::cerr << message << "\n";
#else
#define DEBUG(message)
#endif

const int MOD = 1000 * 1000 * 1000 + 7;

int add(int x, int y) {
  return (x + y) % MOD;
}

int sub(int x, int y) {
  return (x - y + 0LL + MOD) % MOD;
}

bool check(vector<int> vec) {
  int n = (int)vec.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= min(i + vec[i], n - 1); j++) {
      for (int k = i + 1; k <= min(i + vec[i], n - 1); k++) {
        if (vec[j] != vec[k]) {
          return false;
        }
      }
    }
  }
  return true;
}

struct Solver {
  void solve() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    int total = 1;

    for (int i = 1; i <= n; i++) {
      dp[i] = total;
      if (i >= 2) {
        dp[i] = sub(dp[i], dp[i - 2]);
      }
      total = add(total, dp[i]);
    }

//    int calc_slow = 0;
//    for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= n; j++) {
//        for (int k = 1; k <= n; k++) {
//          for (int l = 1; l <= n; l++) {
//            if (check({i, j, k, l})) {
//              DEBUG("" << i << " " << j << " " << k << " " << l);
//              ++calc_slow;
//            }
//          }
//        }
//      }
//    }
//    DEBUG("slow: " << calc_slow);

    int ans = dp[n];
//    DEBUG("dp[n]: " << dp[n]);
    for (int i = 0; i + 1 < n; i++) {
      int res = 1LL * dp[i] * (n - 1) % MOD;
      res = 1LL * res * (n - 1) % MOD;
//      DEBUG("res: " << i << " " << res);
      ans = add(ans, res);
    }
    for (int i = 0; i < n; i++) {
      int mn = max(2, n - i);
      ans = add(ans, 1LL * dp[i] * max(0, n - mn + 1) % MOD);
    }

    cout << ans << "\n";
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  int t = 1;
//  cin >> t;
  for (int i = 1; i <= t; i++) {
    Solver().solve();
  }
  return 0;
}