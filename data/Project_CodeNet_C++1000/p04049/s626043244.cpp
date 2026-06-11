/**
 *    author:  tourist
 *    created: 25.01.2020 20:28:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<vector<int>> dist(n, vector<int>(n, -1));
  for (int start = 0; start < n; start++) {
    vector<int> que(1, start);
    dist[start][start] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      for (int u : g[que[b]]) {
        if (dist[start][u] == -1) {
          que.push_back(u);
          dist[start][u] = dist[start][que[b]] + 1;
        }
      }
    }
  }
  int ans = 0;
  if (k % 2 == 0) {
    for (int v = 0; v < n; v++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        cnt += (dist[v][i] <= k / 2);
      }
      ans = max(ans, cnt);
    }
  } else {
    for (int v = 0; v < n; v++) {
      for (int u : g[v]) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          cnt += (min(dist[v][i], dist[u][i]) <= k / 2);
        }
        ans = max(ans, cnt);
      }
    }
  }
  cout << n - ans << '\n';
  return 0;
}
