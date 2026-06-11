#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
constexpr int INF = 1e9;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

void warshall_floyd(const int& n, vector<vector<int>>& d) {
  rep(k, n) rep(i, n) rep(j, n) chmin(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> to(n);
  vector<vector<int>> d(n, vector<int>(n, INF));
  rep(i, n) d[i][i] = 0;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    d[a][b] = c;
    d[b][a] = c;
    to[a].push_back({b, c});
    to[b].push_back({a, c});
  }

  warshall_floyd(n, d);

  set<pair<int, int>> paths;

  rep(a, n) rep(b, n) {       // a -> b の最短経路
    if (a == b) continue;
    for (auto& p : to[a]) {   // a に隣接しているノード
      int c = p.first;
      if (p.second + d[c][b] == d[a][b]) {
        paths.insert({min(a, c), max(a, c)});
      }
    }
  }

  cout << m - paths.size() << endl;

  return 0;
}
