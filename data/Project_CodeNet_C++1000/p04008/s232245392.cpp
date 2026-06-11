#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; i++)
#define ford(i, r, l) for (int i = r; i >= l; i--)

const int maxn = 1e5 + 5;

vector<int> G[maxn];
int N, K, Ans;
int fa[maxn], dis[maxn];

void dfs(int x) {
  for (int to : G[x]) dfs(to), dis[x] = max(dis[x], dis[to] + 1);
  if (fa[x] != 1 && dis[x] == K - 1) Ans++, dis[x] = -1;
}

int main() {
  scanf("%d%d", &N, &K);
  foru(i, 1, N) scanf("%d", &fa[i]);
  Ans += fa[1] != 1, fa[1] = 1;
  foru(i, 2, N) G[fa[i]].push_back(i);
  memset(dis, 0, sizeof(dis));
  dfs(1);
  printf("%d\n", Ans);
  return 0;
}
