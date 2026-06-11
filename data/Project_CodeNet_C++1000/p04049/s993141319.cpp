// by newbiechd
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

// DELETE the debugging information!
#define debug(x) std::cerr << #x << " = " << (x) << std::endl

const int N_MAX = 2003;
std::vector<int> g[N_MAX];
int u[N_MAX], v[N_MAX];

int lim;
int dfs(int x, int fa, int dis) {
  if (dis > lim)
    return 0;
  int ret = 1;
  for (int y : g[x])
    if (y != fa)
      ret += dfs(y, x, dis + 1);
  return ret;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    u[i] = x, v[i] = y;
  }
  
  lim = k / 2;
  int ans = 0;
  if (k & 1) {
    for (int i = 1; i < n; ++i)
      ans = std::max(dfs(u[i], v[i], 0) + dfs(v[i], u[i], 0), ans);
  }
  else {
    for (int i = 1; i <= n; ++i)
      ans = std::max(dfs(i, 0, 0), ans);
  }
  printf("%d\n", n - ans);
  return 0;
}
