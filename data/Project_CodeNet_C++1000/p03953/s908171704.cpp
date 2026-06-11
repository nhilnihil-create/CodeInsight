#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
#define int long long

int n, m, x[N], a[N];
int s[N], p[N];
int tot, k;
int bel[N], dep[N];
int vis[N];
vector <int> v[N];

void dfs(int u, int depth) {
  dep[u] = depth;
  vis[u] = 1;
  bel[u] = tot;
  v[tot].push_back(u);
  if (!vis[p[u]]) {
    dfs(p[u], depth + 1);
  }
}

signed main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
  }
  for (int i = 1; i < n; i++) {
    s[i] = x[i + 1] - x[i];
    p[i] = i;
  }
  scanf("%lld %lld", &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &a[i]);
    swap(p[a[i]], p[a[i] - 1]);
  }
  for (int i = 1; i < n; i++) {
    if (vis[i] == 0) {
      tot++;
      dfs(i, 0);
    }
  }
  printf("%lld\n", x[1]);
  int cur = x[1];
  for (int i = 1; i < n; i++) {
    cur += s[v[bel[i]][(dep[i] + k) % v[bel[i]].size()]];
    printf("%lld\n", cur);
  }
  return 0;
}