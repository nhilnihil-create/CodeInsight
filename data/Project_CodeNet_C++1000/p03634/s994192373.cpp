#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 17;

int n, timer = 0, q, k;
vector < pair < int, int > > g[maxn];
int tin[maxn], tout[maxn];
int64_t d[maxn];

void dfs (int u, int p) {
  tin[u] = ++timer;
  for (auto pr: g[u]) {
    int v = pr.first, w = pr.second;
    if (v != p) {
      d[v] = d[u] + w;
      dfs(v, u);
    }
  }
  tout[u] = ++timer;
}

bool is_ancestor (int u, int v) {
  return tin[u] >= tin[v] && tout[u] <= tout[v];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  cin >> q >> k;
  dfs(k, -1);
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    cout << d[u] + d[v] << '\n';
  }
}