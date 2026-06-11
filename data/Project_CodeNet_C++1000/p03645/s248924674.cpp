#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> to[n + 1];
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    to[a].emplace_back(b);
    to[b].emplace_back(a);
  }
  vector<bool> exist(n, false);
  for (auto&& e : to[1]) {
    exist[e] = true;
  }
  bool good = false;
  for (auto&& e : to[n]) {
    if (exist[e]) {
      good = true;
      break;
    }
  }
  if (good) {
    cout << "POSSIBLE" << '\n';
  } else {
    cout << "IMPOSSIBLE" << '\n';
  }
  return 0;
}