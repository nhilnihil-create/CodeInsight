#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;

const int M = 2e5 + 10, N = 1e5 + 10;

int n, m, x, y;
struct pas {
  int y, nxt;
} g[M << 1];

int h[N], tot;
bool vis[N];
int f[N];
int t1, t2, t3;

void cover(int x) {
  vis[x] = 1;
  for (int i = h[x]; i; i = g[i].nxt)
    if (!vis[g[i].y]) cover(g[i].y);
}

bool dfs(int x) {
  vis[x] = 1;
  bool ret = 1;
  int i;
  for (i = h[x]; i; i = g[i].nxt)
    if (!vis[g[i].y]) {
      f[g[i].y] = f[x] ^ 1;
      if (!dfs(g[i].y)) {
        ret = 0;
        break;
      }
    } else if (f[g[i].y] == f[x]) {
      ret = 0;
      break;
    }
  for (; i; i = g[i].nxt) cover(g[i].y);
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    g[++tot] = pas{y, h[x]};
    h[x] = tot;
    g[++tot] = pas{x, h[y]};
    h[y] = tot;
  }
  for (int i = 1; i <= n; i++) {
    if (!h[i])
      t1++;
    else if (!vis[i]) {
      if (dfs(i))
        t2++;
      else
        t3++;
    }
  }
  ll ans;
  ans = 1ll * t1 * t1 + 2ll * t1 * (n - t1) + 2ll * t2 * t2 + 2ll * t2 * t3 +
        1ll * t3 * t3;

  printf("%lld", ans);
}
