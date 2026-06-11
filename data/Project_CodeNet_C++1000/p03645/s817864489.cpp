#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> reach(n);
  vector<vector<int>> route(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (b == n - 1) reach[a] = true;
    if (a == 0) route[a].push_back(b);
  }
  bool flag = false;
  for (auto v : route[0]) {
    if (reach[v]) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}