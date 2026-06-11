#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const ll INFll = 1LL << 60;
typedef pair<long, long> PL;
struct Edge {
  ll to;
  ll cost;
};
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる,負のコストの際利用できない
*/
void dijkstra(const vector<vector<Edge>> &G, int s, vector<ll> &dis) {
  int N = G.size();
  dis.resize(N, INFll);
  priority_queue<PL, vector<PL>, greater<PL>>
      pq;  //「仮の最短距離、頂点」が小さい順にならぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    PL p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) continue;  //最短経路でなければ無視
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
        dis[e.to] = dis[v] + e.cost;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}
/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstraRestore(const vector<vector<Edge>> &G, int s, vector<ll> &dis,
                     vector<ll> &prev) {
  int N = G.size();
  dis.resize(N, INFll);
  prev.resize(N, -1);  // 初期化
  priority_queue<PL, vector<PL>, greater<PL>>
      pq;  //「仮の最短距離、頂点」が小さい順にならぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    PL p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) continue;  //最短経路でなければ無視
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
        dis[e.to] = dis[v] + e.cost;
        prev[e.to] = v;  // 頂点 v を通って e.to にたどり着いた
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}

/* get_path(prev, t)
    dijkstraRestore で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<ll> &prev, int t) {
  vector<int> path;
  for (int cur = t; cur != -1; cur = prev[cur]) {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end());  //逆順なのでひっくり返す
  return path;
}
//参考:https://algo-logic.info/dijkstra/
int main() {
  int N, M;
  cin >> N >> M;
  map<P, int> mp;
  vector<vector<Edge>> edge(N);
  REP(i, M) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    edge[a].push_back(Edge{b, c});
    edge[b].push_back(Edge{a, c});
    mp[P(a, b)] = 1;
  }
  for (int i = 0; i < N - 1; i++) {
    vector<ll> dis(0), prev(0);
    dijkstraRestore(edge, i, dis, prev);
    for (int j = i + 1; j < N; j++) {
      vector<int> _a = get_path(prev, j);
      int tmp = i;
      REP(k, _a.size()) {
        mp[P(tmp, _a[k])] = 0;
        mp[P(_a[k], tmp)] = 0;
        tmp = _a[k];
      }
    }
  }
  ll ans = 0;
  for (auto s : mp) {
    if (s.second != 0) {
      ans++;
    }
  }
  cout << ans << endl;
}