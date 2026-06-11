#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  bool ok = false;
  for (auto s : v[0]) {
    for (auto t : v[s])
      if (t == n - 1) {
        puts("POSSIBLE");
        return 0;
      }
  }

  puts("IMPOSSIBLE");
  return 0;
}
