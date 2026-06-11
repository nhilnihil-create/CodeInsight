#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1LL<<61;

struct edge {
  int from;
  int to;
  ll cost;
};

int main() {

  int n, m;
  cin >> n >> m;
  vector<edge> G;
  ll dist[n+1];

  rep(i, m) {
    edge e;
    cin >> e.from >> e.to >> e.cost;
    G.push_back(e);
  }

  fill(dist, dist+n+1, -1 * INF);
  dist[1] = 0;
  bool neg_loop = false;

  // 頂点数-1　回ループして更新する。
  // 頂点数 回目のループで更新があった場合、正の閉路が存在する。
  for(int i = 1; i < n+1; ++i) {
    for(auto &e: G) {
      if(dist[e.to] < dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from]+ e.cost;
        if(i == n && e.to == n) {
          neg_loop = true;
          break;
        }
      }
    }
  }

  if(!neg_loop) cout << dist[n] << endl;
  else cout << "inf" << endl;
  return 0;
}