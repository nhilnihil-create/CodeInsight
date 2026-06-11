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

struct Query {
  i64 u, d, c;
};

i64 n, m, q;
vector<vector<i64>> g;
int main() {
  cin >> n >> m;
  init_n(g, n + 1);
  for (i64 i = 0; i < m; ++i) {
    i64 a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> q;
  vector<Query> qs;
  for (i64 i = 0; i < q; ++i) {
    i64 v, d, c;
    cin >> v >> d >> c;
    qs.push_back({ v, d, c });
  }

  vector<i64> ds(n + 1, -1), cs(n + 1);
  while (!qs.empty()) {
    auto q = qs.back();
    qs.pop_back();
    if (ds[q.u] >= q.d) continue;
    ds[q.u] = q.d;
    if (cs[q.u] == 0) cs[q.u] = q.c;
    queue<pair<i64, i64>> que;
    que.emplace(q.u, q.d);
    while (!que.empty()) {
      auto p = que.front();
      que.pop();
      i64 u, du; tie(u, du) = p;
      i64 dv = du - 1;
      if (dv >= 0) { 
        for (i64 v : g[u]) {
          if (ds[v] < dv) {
            ds[v] = dv;
            que.emplace(v, dv);
          }
          if (cs[v] == 0) cs[v] = q.c;
        }
      }
    }
  }
  for (i64 i = 1; i <= n; ++i) cout << cs[i] << '\n';
  return 0;
}
