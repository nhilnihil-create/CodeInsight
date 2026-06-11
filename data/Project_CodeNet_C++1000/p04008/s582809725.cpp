#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

int ans;
vector<vector<int>> G;

int dfs(int v = 0) {
  int res = 0;
  for (auto &to : G[v]) {
    res = max(res, dfs(to));
  }

  if (a[v] && res == k - 1) {
    res = -1;
    ans++;
  }
  return res + 1;
}

int main() {
  cin >> n >> k;

  a.resize(n);
  for (auto &i : a) cin >> i, i--;

  if (a[0] != 0) {
    a[0] = 0;
    ans++;
  }

  G.resize(n);
  for (int i = 1; i < n; ++i) {
    G[a[i]].push_back(i);
  }

  dfs();

  cout << ans << endl;
}
