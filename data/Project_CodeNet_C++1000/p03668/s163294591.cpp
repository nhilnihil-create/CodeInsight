#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;

int solve(int now, int par);

int main() {
  cin >> n;
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  if (solve(0, -1))
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}

int solve(int now, int par) {
  int res = 0;
  for (auto to : g[now])
    if (to != par) res ^= solve(to, now) + 1;
  return res;
}