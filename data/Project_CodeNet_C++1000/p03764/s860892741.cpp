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

const lli mod = 1e9+7;
lli n, m;
vector<lli> x, y, ax, ay;
int main() {
  cin >> n >> m;
  read_n(x, n); read_n(y, m);
  init_n(ax, n); init_n(ay, m);
  for (lli i=0; i<n-1; ++i) ax[i] = x[i+1] - x[i];
  for (lli i=0; i<m-1; ++i) ay[i] = y[i+1] - y[i];

  lli xs = 0, ys = 0, xt = 0, yt = 0;
  for (lli i=0; i<n-1; ++i) {
    xt += (i+1)*ax[i];
    xs = (xs + xt) % mod;
  }
  for (lli i=0; i<m-1; ++i) {
    yt += (i+1)*ay[i];
    ys = (ys + yt) % mod;
  }
  lli ans = xs * ys % mod;
  cout << ans << endl;
  return 0;
}
