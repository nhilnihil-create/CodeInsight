#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i + 1 < n; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> grundy(n);
  function<void(int, int)> dfs = [&](int v, int pv) {
    for (int to : g[v]) {
      if (to == pv) {
        continue;
      }
      dfs(to, v);
      grundy[v] ^= (grundy[to] + 1);
    }
  };
  dfs(0, -1);
  if (grundy[0] > 0) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
  return 0;
}