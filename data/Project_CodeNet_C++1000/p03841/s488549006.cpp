/**
 *    author:  tourist
 *    created: 27.01.2020 05:50:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    --x[i];
  }
  vector<vector<pair<int, int>>> at(n * n + 1);
  auto Add = [&](int a, int b, int c) {
    at[a].emplace_back(b, c);
  };
  for (int i = 0; i < n; i++) {
    Add(x[i], x[i], i);
    for (int j = 0; j < i; j++) {
      Add(0, x[i] - 1, i);
    }
    for (int j = i + 1; j < n; j++) {
      Add(x[i] + 1, n * n - 1, i);
    }
  }
  multiset<pair<int, int>> s;
  vector<int> ans(n * n);
  for (int i = 0; i < n * n; i++) {
    for (auto& j : at[i]) {
      s.insert(j);
    }
    if (s.empty()) {
      cout << "No" << '\n';
      return 0;
    }
    auto p = *s.begin();
    s.erase(s.begin());
    if (p.first < i) {
      cout << "No" << '\n';
      return 0;
    }
    ans[i] = p.second;
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < n * n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << '\n';
  return 0;
}
