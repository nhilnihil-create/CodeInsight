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

i64 n, l, q;
vector<i64> x;
vector<array<i64, 18>> tab;
int main() {
  cin >> n;
  read_n(x, n, 1);
  x.push_back(x.back() + 1);
  cin >> l >> q;
  init_n(tab, n + 2);
  for (i64 k = 0; k < 18; ++k) tab[n + 1][k] = n + 1;
  for (i64 i = 1; i <= n + 1; ++i) {
    tab[i][0] = lower_bound(begin(x), end(x), x[i] + l + 1) - begin(x) - 1;
  }
  for (i64 k = 1; k < 18; ++k) {
    for (i64 i = 1; i <= n + 1; ++i) {
      tab[i][k] = tab[tab[i][k - 1]][k - 1];
    }
  }
  /*
  for (i64 k = 0; k < 18; ++k) {
    for (i64 i = 1; i <= n; ++i) {
      cerr << tab[i][k] << ' ';
    }
    cerr << endl;
  }
  */
  while (q--) {
    i64 a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    i64 k = 17, ans = 0;
    while (a < b) {
      while (k > 0 && tab[a][k] > b) --k;
      a = tab[a][k];
      ans += 1 << k;
    }
    cout << ans << '\n';
  }
  return 0;
}
