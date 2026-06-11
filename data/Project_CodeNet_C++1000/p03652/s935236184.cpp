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
i64 n, m;
i64 a[301][301];
int main() {
  cin >> n >> m;
  for (i64 i = 0; i < n; ++i) {
    for (i64 j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  i64 ans = bisect(0, n, [&](i64 x) {
    vector<bool> b(m + 1, true);
    while (true) {
      vector<i64> cnt(m + 1);
      for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < m; ++j) {
          i64 k = a[i][j];
          if (b[k]) {
            cnt[k]++;
            break;
          }
        }
      }
      bool ok = true, ex = false;
      for (i64 k = 1; k <= m; ++k) {
        if (cnt[k] > x) {
          b[k] = false;
          ok = false;
        }
        ex |= cnt[k] > 0;
      }
      if (!ex) return false;
      if (ok) return true;
    }
  }); 
  cout << ans << endl;
  return 0;
}
