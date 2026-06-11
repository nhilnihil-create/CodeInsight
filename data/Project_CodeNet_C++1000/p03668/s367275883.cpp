#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y, x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  V<> par(n, -1);
  queue<int> que;
  par[0] = n; que.push(0);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int w : g[v]) if (par[w] == -1) {
      par[w] = v; que.push(w);
    }
  }
  VV<> ch(n);
  for (int i = 1; i < n; i++) ch[par[i]].push_back(i);
  function<int(int)> dfs= [&](int v) {
    int res = 0;
    for (int w : ch[v]) {
      res ^= dfs(w) + 1;
    }
    return res;
  };
  cout << (dfs(0) ? "Alice" : "Bob") << '\n';
}