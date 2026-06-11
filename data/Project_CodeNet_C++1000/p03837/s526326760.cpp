#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (n); ++i)
#define rrep(i, j, n) for (int i = (n)-1; j <= i; --i)

[[maybe_unused]] constexpr int INF = 0x3f3f3f3f;

struct Edge {
  int to, from, cost;
  Edge(int t, int f, int c) : to(t), from(f), cost(c) {}
};

int main() {

  int n, m;
  cin >> n >> m;
  vector<Edge> es;
  vector<vector<int>> g(n, vector<int>(n, INF));
  rep(i, 0, m) {
    int f, t, c;
    cin >> f >> t >> c;
    --f, --t;
    es.emplace_back(f, t, c);
    g[f][t] = c;
    g[t][f] = c;
  }
  rep(i, 0, n) g[i][i] = 0;
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) g[i][j] =
    min(g[i][j], g[i][k] + g[k][j]);

  int ans = 0;
  rep(i, 0, m) if (g[es[i].from][es[i].to] != es[i].cost)++ ans;
  cout << ans << endl;
  return 0;
}
