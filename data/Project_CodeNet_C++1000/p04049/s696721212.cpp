#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 2010;

int n, k, cur;
vector<int> g[N];
bool vis[N];
int dep[N], sub[N];

void dfs(int u) {
  sub[u] = 0;
  vis[u] = true;
  if (dep[u] <= k / 2)
    ++cur;
  for (int v : g[u]) {
    if (vis[v]) continue;
    dep[v] = dep[u] + 1;
    dfs(v);
    sub[u] += sub[v];
  }
  if (k % 2 == 1 && dep[u] == k / 2 + 1)
    ++sub[u];
}

int main() {
//  freopen("test.in", "r", stdin);
//  freopen("test.out", "w", stdout);
  
  scanf("%d%d", &n, &k);
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof(vis));
    dep[i] = 0;
    cur = 0;
    dfs(i);
    int mx = 0;
    if (k & 1)
       for (int v : g[i])
         mx = max(mx, sub[v]);
    ans = max(ans, cur + mx);
  }
  printf("%d\n", n - ans);
  
  return 0;
}

