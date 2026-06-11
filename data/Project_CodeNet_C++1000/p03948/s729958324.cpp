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

lli n, t, a[100001], ma[100001], d[100001];
int main() {
  cin >> n >> t; read_n(a, n);
  
  ma[0] = a[0];
  for (lli i=1; i<n; ++i) ma[i] = min(ma[i-1], a[i]);

  for (lli i=1; i<n; ++i) {
    d[i] = a[i] - ma[i-1];
  }

  sort(&d[0], &d[n], greater<lli>());
  lli ans = 1;
  lli x = d[0];
  for (lli i=1; i<n; ++i) {
    if (x == d[i]) ++ans;
  }
  cout << ans << '\n';
  return 0;
}
