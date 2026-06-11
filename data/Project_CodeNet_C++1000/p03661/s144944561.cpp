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

int main() {
  lli n; vector<lli> a;
  cin >> n;
  init_n(a, n);
  lli l = 0, r = 0;
  for (lli i=0; i<n; ++i) {
    cin >> a[i];
    r += a[i];
  }
  lli ans = 1e18;
  for (lli i=0; i<n-1; ++i) {
    r -= a[i];
    l += a[i];
    ans = min(ans, abs(r-l));
  }
  cout << ans << endl;
  return 0;
}
