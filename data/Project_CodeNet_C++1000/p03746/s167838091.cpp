#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<vector<int>> g;
vector<int> res;
vector<bool> used;

void solve();

int main() {
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  solve();
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i) {
    if (i != 0) cout << " ";
    cout << res[i] + 1;
  }
  cout << endl;
  return 0;
}

void solve() {
  int st = 0;
  while (!g[st].size()) ++st;
  used.assign(n, 0);
  used[st] = 1;
  res.push_back(st);
  for (int now = st, bf = -1; now != bf;) {
    bf = now;
    for (auto to : g[now])
      if (!used[to]) {
        used[to] = 1;
        res.push_back(to);
        now = to;
        break;
      }
  }
  reverse(res.begin(), res.end());
  for (int now = st, bf = -1; now != bf;) {
    bf = now;
    for (auto to : g[now])
      if (!used[to]) {
        used[to] = 1;
        res.push_back(to);
        now = to;
        break;
      }
  }
}
