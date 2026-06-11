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

lli n, m;
vector<vector<lli>> e;
vector<lli> ne;

void dfs(lli v) {
  for (lli to : e[v]) {
    if (ne[to] == -1) {
      ne[v] = to;
      dfs(to);
      return;
    }
  }
  ne[v] = -2;
}

int main() {
  cin >> n >> m;
  init_n(e, n+1);
  for (lli i=0; i<m; ++i) {
    lli a, b; cin >> a >> b;
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }
  
  init_n(ne, n+1, -1);

  dfs(1);
  vector<lli> p1;
  for (lli v=1; v>=0; v=ne[v]) p1.push_back(v);

  ne[1] = -1;
  dfs(1);
  vector<lli> p2;
  for (lli v=1; v>=0; v=ne[v]) p2.push_back(v);
  
  for (lli v : p1) cerr << v << ' '; cerr << '\n';
  for (lli v : p2) cerr << v << ' '; cerr << '\n';

  vector<lli> p;
  for (lli i=p1.size()-1; i>=0; --i) p.push_back(p1[i]);
  for (lli i=1; i<p2.size(); ++i) p.push_back(p2[i]);

  cout << p.size() << '\n';
  bool first = true;
  for (lli v : p) {
    if (first) first = false; else cout << ' ';
    cout << v;
  }
  cout << '\n';
  
  return 0;
}
