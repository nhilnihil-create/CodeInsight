#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
#define maxn 5000010

void read(int &x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
struct node {
  int to;
  int nxt;
} edge[maxn];
int tot, head[maxn], maxx, vis[maxn], ans, cnt;
void add(int x, int y) {
  edge[cnt].to = y;
  edge[cnt].nxt = head[x];
  head[x] = cnt++;
}
void dfs(int now, int fa, int stp) {
  tot++;
  if (stp == 0) return;
  for (int i = head[now]; ~i; i = edge[i].nxt) {
    if (edge[i].to == fa) {
      continue;
    }
    dfs(edge[i].to, now, stp - 1);
  }
}
int n, k;
int main() {
  read(n), read(k);
  int u, v, del;
  for (int i = 0; i <= n; i++) head[i] = -1;
  for (int i = 0; i < n - 1; i++) {
    read(u), read(v);
    add(u, v);
    add(v, u);
  }
  ans = 0;
  if (k % 2 == 0) {  // k为偶数，枚举点，跑k/2的边
    for (int i = 1; i <= n; i++) {
      tot = 0;
      dfs(i, 0, k / 2);
      ans = max(tot, ans);
    }
  } else {  // k为奇数，枚举边，跑k/2的点
    for (u = 1; u <= n; u++) {
      for (int j = head[u]; ~j; j = edge[j].nxt) {
        tot = 0;
        int t = edge[j].to;
        dfs(t, u, k / 2);
        dfs(u, t, k / 2);
        ans = max(tot, ans);
      }
    }
  }
  cout << n - ans << endl;
}
