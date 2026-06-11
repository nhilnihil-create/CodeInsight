#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

template<class F>
i64 bisect(i64 l, i64 r, F f) { // (l, r]
  if (r - l <= 1) return r;
  i64 m = l + (r - l) / 2;
  return f(m) ? bisect(l, m, f) : bisect(m, r, f);
}

i64 n, k;
vector<i64> a;

int main() {
  cin >> n >> k;
  read_n(a, n);
  sort(begin(a), end(a));

  i64 x = bisect(-1, n, [&](i64 l) {
    if (l == n) return true;
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (i64 i = 0; i < n; ++i) {
      if (i == l) continue;
      auto dp_new = dp;
      for (i64 j = 0; j + a[i] < k; ++j) {
        dp_new[j + a[i]] |= dp[j];
      }
      dp = dp_new;
    }
    for (i64 j = k - 1; j >= k - a[l]; --j) {
      if (dp[j] > 0) return true;
    }
    return false;
  });

  cout << x << endl;
  return 0;
}
