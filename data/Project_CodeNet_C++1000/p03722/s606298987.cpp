#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const int MAX = 1000;
static const ll INF = 1e18;

// ベルマンフォード法 O(EV)
vector<pair<int, int>> G[MAX];
vector<ll> dist, neg; // 最短距離
// main関数からこれらを削除すること

// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
  dist = vector<ll>(n, INF); // 大きな数
  neg = vector<ll>(n, 0);
  dist[s] = 0; // 開始点の距離は0
  pair<int, int> p;
  for(int i = 0; i < n; i++){
    for(int v = 0; v < n; v++){
      for(int k = 0; k < G[v].size(); k++){
        p = G[v][k];
        if(dist[v] != INF && dist[p.first] > dist[v] + p.second){
          dist[p.first] = dist[v] + p.second;
          if(i == n - 1) neg[p.first] = 1; // n回目にも更新があるなら負の閉路が存在
        }
      }
    }
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 重み付き無向(有向)グラフの隣接リスト
  int n, m; // n:頂点数 m:辺数
  cin >> n >> m;
  
  //vector<pair<int, int>> G[n]; // G:頂点数がnのグラフを表す隣接リスト
  
  int u, v, w;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].emplace_back(make_pair(v, -w));
    // G[v].emplace_back(make_pair(u, -w)); // 有向グラフではこの行をコメントアウト
  }
  
  bellman_ford(n, 0);
  
  if(neg.at(n - 1)) cout << "inf\n";
  else cout << -dist.at(n - 1) << '\n';
}