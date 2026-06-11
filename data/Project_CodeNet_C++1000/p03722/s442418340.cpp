#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 100100100100100

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

// 隣接リストで使う辺を表す型
struct Edge {
  int to;
  ll cost;  // 辺の接続先頂点, 辺の重み
  Edge(int to, ll cost) : to(to), cost(cost) {}  // コンストラクタ
};

typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
AdjList graph;  // グラフの辺を格納した構造体
                // graph[v][i]は頂点vから出るi番目の辺Edge


vector<ll> dist; // 最短距離

// 戻り値がtrueなら負の閉路を含む
void bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
  dist = vector<ll>(n, INF);
  dist[s] = 0; // 開始点の距離は0
  bool loop=false;
  for (int i = 0; i < n; i++) {
    for (int v = 0; v < n; v++) {
      for (int k = 0; k < graph[v].size(); k++) {
        Edge e = graph[v][k];
        if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          if (i == n - 1){
            dist[e.to]=-INF;
            loop=true;
          } // n回目にも更新があるなら負の閉路が存在
        }
      }
    }
  }
  if(loop){
    for (int i = 0; i < n; i++) {
      for (int v = 0; v < n; v++) {
        for (int k = 0; k < graph[v].size(); k++) {
          Edge e = graph[v][k];
          if (dist[v] ==-INF) {
            dist[e.to] = -INF;
          }
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  graph = AdjList(n);

  for (int i = 0; i < m; i++) {
    int from, to;
    ll cost;
    cin >> from >> to >> cost;
    --from; --to;
    cost*=-1;
    graph[from].push_back(Edge(to, cost));
  }
  bellman_ford(n, 0);
  if(dist[n-1]==-INF){
    cout << "inf" << endl;
  } else {
    cout << -dist[n-1] << endl;
  }
  return 0;
}
