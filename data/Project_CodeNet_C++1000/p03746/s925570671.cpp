#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  vector<bool> vis(n);
  vector<int> p1, p2;
  function<void(int)> dfs = [&](int v) {
    vis[v] = true;
    p1.push_back(v);
    for (int i : e[v]) {
      if (!vis[i]) {
        dfs(i);
        break;
      }
    }
  };
  dfs(1);
  swap(p1, p2);
  dfs(1);
  reverse(p1.begin(), p1.end());
  p1.pop_back();
  p1.insert(p1.end(), p2.begin(), p2.end());
  cout << p1.size() << endl;
  for (int i : p1) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
