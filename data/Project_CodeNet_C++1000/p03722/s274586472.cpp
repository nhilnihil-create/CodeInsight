#include <bits/stdc++.h>
using namespace std;

int main() {
  const long inf = 1l << 60;
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> to(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    to.at(a).emplace_back(b, -c);
  }
  vector<long> cost(n, inf);
  cost.at(0) = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      for (auto x : to.at(j)) {
        cost.at(x.first) = min(cost.at(x.first), cost.at(j) + x.second);
      }
    }
  }
  long ans = cost.at(n - 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (auto x : to.at(j)) {
        cost.at(x.first) = min(cost.at(x.first), cost.at(j) + x.second);
      }
    }
  }
  if (cost.at(n - 1) != ans) {
    cout << "inf" << endl;
  } else {
    cout << -ans << endl;
  }
}
