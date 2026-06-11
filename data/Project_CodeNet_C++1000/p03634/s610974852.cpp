#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<pair<int, int64_t>>> &to, vector<int64_t> &d, int v, int p) {
  for (auto next : to.at(v)) {
    if (next.first == p) continue;
    d.at(next.first) = d.at(v) + next.second;
    dfs(to, d, next.first, v);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int64_t>>> to(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    to.at(a).emplace_back(b, c);
    to.at(b).emplace_back(a, c);
  }
  int q, k;
  cin >> q >> k;
  k--;
  vector<int64_t> d(n);
  dfs(to, d, k, -1);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << d.at(x) + d.at(y) << "\n";
  }
}
