#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, fa[N], f[N], d[N];
vector<int> g[N];
void dfs(int u) {
  for (auto v : g[u]) {
    dfs(v);
    d[u] = max(d[u], d[v] + 1);
    f[u] += f[v];
  }
  if (d[u] == k - 1 && u != 1 && fa[u] != 1) {
    d[u] = -1;
    ++f[u];
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &fa[i]);   
    if (i > 1) {
      g[fa[i]].push_back(i);
    }
  }
  dfs(1);
  printf("%d\n", (fa[1] != 1) + f[1]);
  return 0;
}