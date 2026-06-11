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

lli n, k;
vector<lli> e[2001];

lli dfs(lli u, lli p, lli d) {
  lli res = d > k/2 ? 1 : 0;
  for (lli v : e[u]) {
    if (v != p) res += dfs(v, u, d + 1);
  }
  return res;
}

int main() {
  cin >> n >> k;
  for (lli i=0; i<n-1; ++i) {
    lli u, v; cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  lli ans = 1e10;
  if (k % 2 == 1) {
    for (lli i=1; i<=n; ++i) {
      for (lli v : e[i]) {
        if (v > i) ans = min(ans, dfs(i, v, 0) + dfs(v, i, 0));
      }
    }
  } else {
    for (lli i=1; i<=n; ++i) {
      ans = min(ans, dfs(i, -1, 0));
    }
  }

  cout << ans << '\n';
  return 0;
}
