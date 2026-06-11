#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ipair = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> s(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    s[a].push_back(b);
    s[b].push_back(a);
  }

  vector<int> cost(n + 1, -1);
  priority_queue<ipair, vector<ipair>, greater<ipair>> que;
  que.push({0, 1});
  cost[1] = 0;
  while (!que.empty()) {
    auto c = que.top().first;
    auto num = que.top().second;
    que.pop();

    for (size_t i = 0; i < s[num].size(); i++) {
      auto next = s[num][i];
      if (cost[next] == -1) {
        que.push({c + 1, next});
        cost[next] = c + 1;
      }
    }
  }
  if (cost[n] == 2) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
