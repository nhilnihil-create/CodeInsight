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

i64 n;
vector<i64> a;
int main() {
  cin >> n;
  read_n(a, n);
  vector<i64> cnt(n);
  for (i64 x : a) cnt[x]++;

  for (i64 d = 1; d < n; ++d) {
    i64 r = (d + 1) / 2;
    bool ok = true;
    if (d % 2 == 0) {
      if (cnt[r] != 1) ok = false;
    } else {
      if (cnt[r] != 2) ok = false;
    }
    for (i64 i = 1; i < r; ++i) {
      if (cnt[i] != 0) ok = false;
    }
    for (i64 i = r + 1; i <= d; ++i) {
      if (cnt[i] < 2) ok = false;
    }
    for (i64 i = d + 1; i < n; ++i) {
      if (cnt[i] != 0) ok = false;
    }
    if (ok) {
      cout << "Possible\n";
      return 0;
    }
  }
  cout << "Impossible\n";
  return 0;
}
