#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100;
static const int INF = 1e9;

map<pair<int, int>, int> mp;

// ワ―シャルフロイド法 O(V^3)
void warshall_floyd(vector<vector<int>> &M) { // 隣接行列Mを書き換える
  int n = M.size();
  for (int i = 0; i < n; i++) // 経由する頂点
    for (int j = 0; j < n; j++) // 始点
      for (int k = 0; k < n; k++) // 終点
        M[j][k] = min(M[j][k], M[j][i] + M[i][k]);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 重み付き無向(有向)グラフの隣接リスト
  int n, m; // n:頂点数 m:辺数
  cin >> n >> m;
  
  vector<vector<int>> M(n, vector<int>(n, INF)); // M:頂点数がnのグラフを表す隣接行列(初期値INF)
  for (int i = 0; i < n; i++) M[i][i] = 0;
  
  vector<pair<int, int>> G[n]; // G:頂点数がnのグラフを表す隣接リスト
  
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    M[u][v] = w;
    M[v][u] = w; // 重み付き有向グラフではこの行をコメントアウト
    G[u].emplace_back(make_pair(v, w));
    G[v].emplace_back(make_pair(u, w)); // 有向グラフではこの行をコメントアウト
  }
  
  warshall_floyd(M);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < G[j].size(); k++) {
        if (M[i][j] + G[j][k].second == M[i][G[j][k].first]) {
          if (j < G[j][k].first) mp[make_pair(j, G[j][k].first)]++;
          else mp[make_pair(G[j][k].first, j)]++;
        }
      }
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < G[i].size(); j++) {
      if (i > G[i][j].first) continue;
      if (mp[make_pair(i, G[i][j].first)] > 0) ans++;
    }
  }
  
  cout << m - ans << '\n';
}