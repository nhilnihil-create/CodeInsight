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

i64 n, k;
vector<i64> a, b;
int main() {
  cin >> n >> k;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  i64 ans = 0;
  for (int d = -1; (1ll << d) <= k; ++d) {
    if (d >= 0 && !(k & (1ll << d))) continue;

    i64 x; 
    if (d >= 0) {
      x = (k | ((1ll << d) - 1)) & (~(1ll << d));
    } else {
      x = k;
    }

    cerr << d << ' ' << x << endl;

    i64 v = 0;
    for (int i = 0; i < n; ++i) {
      if (!(a[i] & ~x)) {
        v += b[i];
      }
    }
    ans = max(ans, v);
  }

  cout << ans << endl;
  return 0;
}