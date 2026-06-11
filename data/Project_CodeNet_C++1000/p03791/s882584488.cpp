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

const i64 mod = 1e9 + 7;
i64 n;
vector<i64> x;
int main() {
  cin >> n;
  read_n(x, n);

  i64 b = 0, ans = 1;
  for (i64 i = 0; i < n; ++i, ++b) {
    if (x[i] <= 2 * b) {
      (ans *= (b + 1)) %= mod;
      --b;
    }
  }
  for (; b > 0; --b) (ans *= b) %= mod;
  cout << ans << endl;
  return 0;
}

// *.**..*..
// 123456
