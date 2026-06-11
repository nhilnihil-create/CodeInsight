#include <bits/stdc++.h>

using namespace std;

int read();

int n, root;
int a[200005], up[200005];
vector<int> e[200005];
void add(int f, int t) { e[f].push_back(t), e[t].push_back(f); }
void dfs(int u, int fa) {
  if (e[u].size() == 1) return up[u] = a[u], void();
  int mx = 0, sum = 0;
  for (int i = 0, v; i < (int)e[u].size(); ++i)
    if ((v = e[u][i]) != fa) dfs(v, u), sum += up[v], mx = max(mx, up[v]);
  up[u] = 2 * a[u] - sum;
  if (up[u] < 0 || up[u] > a[u] || a[u] < mx) puts("NO"), exit(0);
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  if (n == 2) return puts(a[1] == a[2] ? "YES" : "NO"), 0;
  for (int i = 1, u, v; i < n; ++i) u = read(), v = read(), add(u, v);
  for (int i = 1; i <= n; ++i)
    if (e[i].size() > 1) root = i;
  dfs(root, 0), puts(up[root] ? "NO" : "YES");
  return 0;
}

int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
