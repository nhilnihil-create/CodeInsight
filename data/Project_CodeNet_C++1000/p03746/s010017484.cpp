#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  deque<int> ans;
  vector<int> vis(n, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    if (i == 0) {
      ans.push_back(u);
      ans.push_back(v);
      vis[u] = vis[v] = 1;
    }
    g[u].push_back(v);
    g[v].push_back(u);
  }
  while (true) {
    bool ok = true;
    int end = ans.front();
    for (int nbr : g[end]) {
      if (vis[nbr]) continue;
      ok = false;
      vis[nbr] = 1;
      ans.push_front(nbr);
      break;
    }
    end = ans.back();
    for (int nbr : g[end]) {
      if (vis[nbr]) continue;
      ok = false;
      vis[nbr] = 1;
      ans.push_back(nbr);
      break;
    }
    if (ok) break;
  }
  cout << (int) ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;
  return 0;	
}