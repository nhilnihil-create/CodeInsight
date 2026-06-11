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
#define DEBUG(message) std::cerr << message << std::endl;
#else
#define DEBUG(message)
#endif

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> pref(n + 1, 0), suf(n + 2, 0), sum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1] += pref[i];
    sum[i + 1] += sum[i];

    sum[i + 1] += a[i];
    if (a[i] > 0) {
      pref[i + 1] += a[i];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i + 1] += suf[i + 2];
    if (a[i] > 0) {
      suf[i + 1] += a[i];
    }
  }

  ll ans = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    ans = max(ans, pref[i - 1] + suf[i + k] + max(0LL, sum[i + k - 1] - sum[i - 1]));
  }

  cout << ans << "\n";
}

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
    solve();
  }
  return 0;
}