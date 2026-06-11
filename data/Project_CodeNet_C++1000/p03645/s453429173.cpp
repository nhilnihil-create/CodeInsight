#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> d(n);
  rep(i, m) {
    cin >> a >> b;
    a--, b--;
    d[a].push_back(b);
    d[b].push_back(a);
  }

  rep(i, d[0].size()) {
    int ni = d[0][i];
    rep(j, d[ni].size()) {
      if (d[ni][j] == n - 1) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
