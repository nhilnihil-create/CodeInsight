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

i64 n;
vector<vector<int>> g;

i64 dfs(int u) {
  vector<i64> x;
  for (int v : g[u]) {
    x.push_back(dfs(v));
  }
  sort(begin(x), end(x));
  reverse(begin(x), end(x));
  i64 res = 0;
  for (i64 i = 0; i < x.size(); ++i) {
    res = max(res, x[i] + i + 1);
  }
  return res;
}

int main() {
  cin >> n;
  init_n(g, n + 1);
  for (i64 i = 2; i <= n; ++i) {
    i64 p;
    cin >> p;
    g[p].push_back(i);
  }
  i64 ans = dfs(1);
  cout << ans << endl;
  return 0;
}
