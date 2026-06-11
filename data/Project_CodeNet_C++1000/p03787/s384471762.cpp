#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 100100;

vector <int> G[N], vec[2];
int cnt, flag;
int vis[N];

void dfs(int u, int f) {
  ++ cnt;
  for (int v : G[u]) {
    if (v == f) continue;
    if (vis[v]) {
      if (vis[v] == vis[u]) flag = 1; continue;
    }
    vis[v] = 3 - vis[u];
    dfs(v, u);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0, u, v; i < m; i ++)
    scanf("%d %d", &u, &v), G[u].push_back(v), G[v].push_back(u);
  int num = n;
  for (int i = 1; i <= n; i ++) {
    if (vis[i]) continue;
    flag = cnt = 0;
    vis[i] = 1;
    dfs(i, 0);
    if (cnt == 1)
      num --;
    else if (flag)
      vec[0].push_back(cnt);
    else
      vec[1].push_back(cnt);
  }
  LL ans = 1LL * n * n - 1LL * num * num;
  ans += 1LL * (vec[0].size() + vec[1].size()) * (vec[0].size() + vec[1].size()) + 1LL * vec[1].size() * vec[1].size();
  cout << ans << endl;
  return 0;
}