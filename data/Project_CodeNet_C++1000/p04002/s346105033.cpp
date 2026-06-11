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
#include <cassert>
#include <utility>
#include <functional>
#include <bitset>
#include <cstdint>

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

i64 h, w, n;
using P = pair<i64, i64>;
set<P> ps;
int main() {
  cin >> h >> w >> n;
  set<P> st;
  for (i64 i = 0; i < n; ++i) {
    i64 a, b;
    cin >> a >> b;
    ps.emplace(a, b);
    for (i64 da = -2; da <= 0; ++da) {
      for (i64 db = -2; db <= 0; ++db) {
        i64 ta = a + da, tb = b + db;
        if (0 < ta && ta + 2 <= h && 0 < tb && tb + 2 <= w) {
          st.emplace(ta, tb);
        }
      }
    }
  }
  
  vector<i64> ans(10);
  for (const auto& p : st) {
    i64 a = p.first, b = p.second, c = 0;
    for (i64 da = 0; da < 3; ++da) {
      for (i64 db = 0; db < 3; ++db) {
        i64 ta = a + da, tb = b + db;
        c += ps.count({ta, tb});
      }
    }
    ans[c]++;
  }
  
  cout << (h - 2) * (w - 2) - accumulate(begin(ans), end(ans), 0) << '\n';
  for (i64 i = 1; i <= 9; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}

