#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
int n, m;
vector<int> e[N];
int q[N], f, r;
int vis[N];
int check(int u) {
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (!vis[v]) return v;
  }
  return -1;
}
int main() {
  while (cin >> n >> m) {
    bool flag = true;
    for (int i = 1; i <= n; i++) e[i].clear(), vis[i] = 0;
    int u, v;
    f = 1e5, r = 1e5 + 1;
    while (m--) {
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
      if (flag) {
        flag = false;
        vis[u] = vis[v] = 1;
        q[f] = u;
        q[r] = v;
      }
    }

    while (true) {
      int u = check(q[f]);
      if (u == -1)
        break;
      else {
        q[--f] = u;
        vis[u] = 1;
      }
    }
    while (true) {
      int u = check(q[r]);
      if (u == -1)
        break;
      else {
        q[++r] = u;
        vis[u] = 1;
      }
    }
    cout << r - f + 1 << endl;
    while (f <= r) printf("%d ", q[f++]);
    cout << endl;
  }
  return 0;
}
