#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
int dfs (int cur, const vector<vector<int>>& g) {
  vector<int> v;
  for (int nxt : g[cur]) {
    v.push_back(dfs(nxt, g));
  }
  sort(v.rbegin(), v.rend());
  int res = 0;
  for (int i = 0; i < (int) g[cur].size(); i++) {
    res = max(res, i + 1 + v[i]);
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    g[--a].push_back(i);
  }
  cout << dfs(0, g) << '\n';
  return 0;
}