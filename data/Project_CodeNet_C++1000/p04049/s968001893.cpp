#include <bits/stdc++.h>
using namespace std;
#define all(container) (continer).begin(), (container).end()
#define sz(container)  (int) (container).size();
#define rall(container) (container).rbegin(), (container).rend()
using ll = long long;

#ifdef LOCAL_DEFINE
    #include "../../library/DEBUG.hpp"
#else
    #define debug(...) 0
#endif

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
const int maxn = 2100;
vector<int> g[maxn];
vector<vector<int>> distances;
vector<bool> visited;

void bfs(int start) {
  queue<int> Q;
  Q.push(start);
  fill(visited.begin(), visited.end(), false);
  visited[start] = true;
  distances[start][start] = 0;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (auto& v : g[cur]) {
      if (visited[v]) continue;
      visited[v] = true;
      distances[start][v] = 1 + distances[start][cur];
      Q.push(v);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  distances.resize(n, vector<int>(n, 0));
  visited.resize(n, false);
  vector<pair<int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int from, to;
    cin >> from >> to;
    --from, --to;
    g[from].push_back(to);
    g[to].push_back(from);
    edges.emplace_back(from, to);
  }
  for (int i = 0; i < n; i++) bfs(i);
  if (!(k & 1)) {
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        if (distances[i][j] > (k >> 1)) ++cnt;
      }
      uin(ans, cnt);
    }
    cout << ans << '\n';
  } else {
    int ans = INT_MAX;
    for (int i = 0; i < (int) edges.size(); i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (distances[edges[i].first][j] > ((k - 1) >> 1) && distances[edges[i].second][j] > ((k - 1) >> 1)) {
          ++cnt;
        }
      }
      uin(ans, cnt);
    }
    cout << ans << '\n';
  }
  return 0;
}