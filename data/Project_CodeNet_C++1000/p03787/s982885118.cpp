#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, m; cin >> n >> m;
  VV<> g(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v, u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> vis(n);
  lint a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) if (!vis[i]) {
    if (g[i].empty()) {
      vis[i] = 1;
      a++;
    } else {
      bool bi = true;
      queue<int> q;
      vis[i] = 1; q.push(i);
      while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto&& i : g[v]) {
          if (vis[i]) {
            if (vis[i] == vis[v]) bi = false;
            continue;
          }
          vis[i] = -vis[v]; q.push(i);
        }
      }
      (bi ? b : c)++;
    }
  }
  lint res = (b + c) * (b + c) + b * b + 2 * n * a - a * a;
  cout << res << '\n';
}