/**
 *    author:  tourist
 *    created: 10.01.2020 23:13:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int tt;
  cin >> tt;
  vector<int> v(tt);
  vector<int> d(tt);
  vector<int> c(tt);
  for (int i = 0; i < tt; i++) {
    cin >> v[i] >> d[i] >> c[i];
    --v[i];
  }
  vector<int> color(n, -1);
  vector<int> bound(n, -1);
  for (int it = tt - 1; it >= 0; it--) {
    if (d[it] <= bound[v[it]]) {
      continue;
    }
    vector<int> que(1, v[it]);
    bound[v[it]] = d[it];
    if (color[v[it]] == -1) {
      color[v[it]] = it;
    }
    for (int b = 0; b < (int) que.size(); b++) {
      for (int j : g[que[b]]) {
        if (bound[que[b]] - 1 > bound[j]) {
          que.push_back(j);
          bound[j] = bound[que[b]] - 1;
          if (color[j] == -1) {
            color[j] = it;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (color[i] == -1 ? 0 : c[color[i]]) << '\n';
  }
  return 0;
}
