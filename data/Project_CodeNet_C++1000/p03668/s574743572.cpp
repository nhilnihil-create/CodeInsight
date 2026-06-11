#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int dfs(int node, int parent, const vector<vector<int>> &edge) {
  int grundy = 0;
  for (int c : edge[node]) {
    if (c != parent) {
      grundy ^= dfs(c, node, edge) + 1;
    }
  }
  return grundy;
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> edge(N);
  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  cout << (dfs(0, 0, edge) != 0 ? "Alice" : "Bob") << "\n";

  return 0;
}