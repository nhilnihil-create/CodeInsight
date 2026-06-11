#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

void Brute(int n, int m) {
  vector<vector<int>> adj(n, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u][v] = adj[v][u] = 1;
  }
  vector<int> uf(n * n);
  for (int i = 0; i < n * n; ++i) uf[i] = i;

  function<int(int)> Find = [&](int u) {
    if (uf[u] == u) return u;
    return uf[u] = Find(uf[u]);
  };

  auto Merge = [&](int u, int v) { uf[Find(u)] = Find(v); };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
          if (adj[i][k] && adj[j][l]) {
            Merge(i * n + j, k * n + l);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n * n; ++i) ans += Find(i) == i;
  printf("%d\n", ans);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> color(n, -1);

  int sz = 0;
  function<bool(int, int)> Dfs = [&](int x, int c) {
    color[x] = c;
    sz++;
    bool res = true;
    for (int u : g[x]) {
      if (color[u] == -1) {
        if (!Dfs(u, c ^ 1)) res = false;
      } else {
        if (color[u] == color[x]) res = false;
      }
    }
    return res;
  };

  int iso = 0, bip = 0, oth = 0;
  for (int i = 0; i < n; ++i) {
    if (color[i] >= 0) continue;
    sz = 0;
    if (g[i].empty()) {
      ++iso;
    } else if (Dfs(i, 0)) {
      ++bip;
    } else {
      ++oth;
    }
  }
  long long ans = oth + 2 * bip + 1LL * oth * (oth - 1) +
                  1LL * bip * (2 * bip - 2) + 2LL * oth * bip +
                  1LL * iso * iso + 2LL * iso * (n - iso);
  printf("%lld\n", ans);
  return 0;
}
