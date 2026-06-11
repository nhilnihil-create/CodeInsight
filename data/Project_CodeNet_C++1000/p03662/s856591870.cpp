/**
 *    author:  tourist
 *    created: 20.11.2019 14:13:00       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<vector<int>> dd;
  for (int rot = 0; rot < n; rot += n - 1) {
    vector<int> dist(n, n);
    dist[rot] = 0;
    vector<int> que(1, rot);
    for (int b = 0; b < (int) que.size(); b++) {
      for (int j : g[que[b]]) {
        if (dist[j] == n) {
          dist[j] = dist[que[b]] + 1;
          que.push_back(j);
        }
      }
    }
    dd.push_back(dist);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans += (dd[0][i] <= dd[1][i]);
  cout << (ans > n - ans ? "Fennec" : "Snuke") << '\n';
  return 0;
}
