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

i64 h, w, a, b;
int main() {
  cin >> h >> w >> a >> b;
  vector<vector<i64>> res(h);

  if (a == 1 && b == 1) {
    cout << "No\n";
    return 0;
  }

  const i64 C = 1000000000;
  i64 x = (C - 1) / (a * b - 1);

  for (i64 i = 0; i < h; ++i) res[i].assign(w, x);

  for (i64 i = a - 1; i < h; i += a) {
    for (i64 j = b - 1; j < w; j += b) {
      res[i][j] = -C;
    }
  }

  i64 sum = 0;
  for (i64 i = 0; i < h; ++i) {
    for (i64 j = 0; j < w; ++j) {
      sum += res[i][j];
    }
  }

  if (sum > 0) {
    cout << "Yes\n";
    for (i64 i = 0; i < h; ++i) {
      for (i64 j = 0; j < w; ++j) {
        cout << res[i][j] << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << "No\n";
  }
  return 0;
}

// 1  1 1  1
// 1 -4 1 -4
// 1  1 1  1
