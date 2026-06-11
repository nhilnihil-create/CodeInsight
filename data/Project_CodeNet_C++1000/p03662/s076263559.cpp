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

lli n;
vector<vector<lli>> e;
int main() {
  cin >> n;
  init_n(e, n+1);
  for (lli i=0; i<n-1; ++i) {
    lli a, b; cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  // bfs
  vector<lli> dist[2];
  for (lli i=0; i<2; ++i) {
    queue<lli> q;
    dist[i] = vector<lli>(n+1, -1);
    lli s = i==0 ? 1 : n;
    dist[i][s] = 0;
    q.push(s);
    while (!q.empty()) {
      lli v = q.front(); q.pop();
      for (lli u : e[v]) {
        if (dist[i][u] < 0) {
          q.push(u);
          dist[i][u] = dist[i][v] + 1;
        }
      }
    }
  }

  lli cnt = 0;
  for (lli i=1; i<=n; ++i) {
    //cout << i << ':' << dist[0][i] << '-' << dist[1][i] << endl;
    if (dist[0][i] <= dist[1][i]) ++cnt;
  }
  bool ans = cnt > (n-cnt);
  cout << (ans ? "Fennec" : "Snuke") << endl;

  return 0;
}
