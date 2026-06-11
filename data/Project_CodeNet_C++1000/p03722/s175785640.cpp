// https://atcoder.jp/contests/abc065/tasks/arc076_b

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pow(x) x*x
#define ll long long
static const int MAX = 100010;
static const ll INFTY = 1e18;

struct pos {
    ll x;
    ll y;
};
struct edge {
    ll to;
    ll cost;
};
using Graph = vector<vector<edge>>;
// <最短距離, 頂点の番号>
using P = pair<ll, ll>;

vector<ll> dist; // 最短距離
// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(const Graph &G, int n, int s) { // nは頂点数、sは開始頂点
  dist = vector<ll>(n, INFTY);
  dist[s] = 0; // 開始点の距離は0
  for (int i = 0; i < n*2; i++) {
    for (int v = 0; v < n; v++) {
      for (int k = 0; k < G[v].size(); k++) {
        edge e = G[v][k];
        // cout << v << endl;;
        if (dist[v] != INFTY && dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          if (e.to == n-1 && i == 2 * n-1) return true; // n回目にも更新があるなら負の閉路が存在
        }
      }
    }
  }
  return false;
}


int main() {

    ll N, M;    cin >> N >> M;
    Graph G(N);
    REP(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--; c *= -1;
       G[a].push_back({b, c});
    }

    bool ans = bellman_ford(G, N, 0);

    if(ans == false){
        cout << -dist[N-1] << endl;
    } else{
        cout << "inf" << endl;
    }
    
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/