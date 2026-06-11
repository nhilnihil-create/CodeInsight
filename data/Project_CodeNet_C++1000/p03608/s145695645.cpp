#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;
void dijkstra(const int n, vector<vector<int>> &min_path, const vector<vector<pair<int, int>>> &G, const vector<int> &R) {
  for (int i = 0; i < R.size(); i++) {
    int start = R[i];
    vector<int> cost(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, start});
    cost[start] = 0;
    while (!Q.empty()) {
      int x, c;
      tie(c, x) = Q.top();
      Q.pop();
      if (cost[x] < c) continue;

      for (auto y: G[x]) {
        if (cost[y.first] <= y.second + c) continue;
        cost[y.first] = y.second + c;
        Q.push({y.second + c, y.first});
      }
    }
    for (int j = 0; j < R.size(); j++) {
      min_path[i][j] = cost[R[j]];
    }
  }
}

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> R(r);
  for (int i = 0; i < r; i++) cin >> R[i];
  vector<vector<pair<int, int>>> G(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  vector<vector<int>> min_path(r, vector<int>(r));
  dijkstra(n, min_path, G, R);
  vector<vector<int>> dp(1<<r, vector<int>(r, INF));

  for (int i = 0; i < r; i++) dp[0][i] = 0;

  for (int i = 1; i < (1 << r); i++) {
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < r; k++) {
        if ((i & (1 << j)) && (i & (1 << k))) {
          dp[i][k] = min(dp[i][k], dp[i ^ (1 << k)][j] + min_path[j][k]);
        }
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < r; i++) ans = min(ans, dp[(1 << r) - 1][i]);

  cout << ans << endl;
  return 0;
}