#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<vector<int>> g;

long long solve();

int main() {
  cin >> n >> k;
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  using P = pair<long long, long long>;
  function<P(int, int, int)> dfs = [&](int now, int par, int dep) {
    P res(dep >= k / 2 + 1, 0);
    if ((k & 1) && dep == (k + 1) / 2) res.second = 1;
    for (auto to : g[now])
      if (par != to) {
        P tmp = dfs(to, now, dep + 1);
        if (par >= 0)
          res = P(res.first + tmp.first, res.second + tmp.second);
        else
          res = P(res.first + tmp.first, max(res.second, tmp.second));
      }
    if (par < 0) res.first -= res.second;
    return res;
  };
  long long res = n + 1;
  for (int i = 0; i < n; ++i) res = min(res, dfs(i, -1, 0).first);
  return res;
}
