#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <random>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0)
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli udiv(lli x, lli y) {
  return (x + y - 1) / y;
}

lli n, a, b, h[100001];
int main() {
  cin >> n >> a >> b;
  read_n(h, n);

  lli l = 1, r = 1e9+1, ans = 1e18;
  while (true) {
    lli m = (r-l) / 2 + l;
    lli s = 0;
    for (lli i=0; i<n; ++i) {
      s += max(0ll, udiv(h[i] - b*m, a - b));
    }
    cerr << m << ' ' << s << endl;
    if (s <= m) ans = min(ans, m);
    if (l >= r-1) break;
    if (s <= m) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << ans << '\n';
  return 0;
}
