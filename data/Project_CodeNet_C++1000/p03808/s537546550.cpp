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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  ll s = 0;
  multiset<int> diffs;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for (int i = 0; i < n; i++) {
    diffs.insert(a[(i + 1) % n] - a[i]);
  }
  if (s % (n * (n + 1LL) / 2LL) != 0) {
    cout << "NO\n";
    return;
  }
  ll count = s / (n * (n + 1LL) / 2LL);
  ll target = count;
  for (auto x : diffs) {
    if (x == target) {
      continue;
    }
    if (x > target) {
      cout << "NO\n";
      return;
    }
    if ((target - x) % n != 0) {
      cout << "NO\n";
      return;
    }
    count -= (target - x) / n;
  }
  if (count == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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