#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> g;
vector<int> a, high;

int solve();
int dfs(int now, int par);

int main() {
  cin >> n >> k;
  a.resize(n);
  for (auto& p : a) {
    cin >> p;
    --p;
  }
  cout << solve() << endl;
  return 0;
}

int solve() {
  high.assign(n, 0);
  g.resize(n);
  for (int i = 1; i < n; ++i) g[a[i]].push_back(i);
  return dfs(0, -1) + (a[0] != 0);
}

int dfs(int now, int par) {
  int res = 0;
  for (auto to : g[now])
    if (to != par) {
      res += dfs(to, now);
      high[now] = max(high[now], high[to] + 1);
    }
  if (high[now] == k - 1) {
    res += (par != 0 && now != 0);
    high[now] = -1;
  }
  return res;
}