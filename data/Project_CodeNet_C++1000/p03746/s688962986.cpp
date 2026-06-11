#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<int> res;
  vector<bool> used(N, false);
  function<void(int)> f = [&](int i) {
    res.emplace_back(i);
    used[i] = true;
    for (int j : G[i]) {
      if (!used[j]) {
        f(j);
        break;
      }
    }
  };
  f(0);
  reverse(res.begin(), res.end());
  used[0] = false;
  res.pop_back();
  f(0);
  cout << res.size() << '\n';
  for (const auto &v : res) {
    cout << v + 1 << (&v == &res.back() ? '\n' : ' ');
  }
  return 0;
}
