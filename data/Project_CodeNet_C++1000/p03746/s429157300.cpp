/**
 *    author:  tourist
 *    created: 06.01.2020 23:01:53       
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
  vector<int> was(n, 0);
  deque<int> path(1, 0);
  was[0] = 1;
  while (true) {
    bool found = false;
    for (int x : g[path.back()]) {
      if (!was[x]) {
        path.push_back(x);
        was[x] = 1;
        found = true;
        break;
      }
    }
    if (!found) {
      break;
    }
  } 
  while (true) {
    bool found = false;
    for (int x : g[path.front()]) {
      if (!was[x]) {
        path.push_front(x);
        was[x] = 1;
        found = true;
        break;
      }
    }
    if (!found) {
      break;
    }
  } 
  cout << path.size() << '\n';
  for (int i = 0; i < (int) path.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << path[i] + 1;
  }
  cout << '\n';
  return 0;
}
