#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template <class T>
/*  ワーシャルフロイド
    O(V)，全店最短路
    dis[i][i]=0を入力しておく
    dis[i][j]に，辺i-jのコストを入力しておく
    辺がなかったらINF
    負の閉路があったらdis[i][i]が負になるものが存在する*/
void warshall_floyd(T &dis) {
  int V = dis.size();
  REP(k, V) {
    REP(i, V) {
      if (dis[i][k] == INF) continue;
      REP(j, V) {
        if (dis[k][j] == INF) continue;
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> edge(M);
  vector<vector<ll>> dis(N, vector<ll>(N, INF));
  REP(i, N) dis[i][i] = 0;
  REP(i, M) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    edge[i] = make_tuple(a, b, c);
    dis[a][b] = c;
    dis[b][a] = c;
  }
  warshall_floyd(dis);
  ll ans = 0;
  REP(i, M) {
    int a = get<0>(edge[i]), b = get<1>(edge[i]), c = get<2>(edge[i]);
    bool ok = false;
    REP(j, N) {
      for (int k = j + 1; k < N; k++) {
        if (dis[j][a] + c + dis[b][k] == dis[j][k]) ok = true;
        if (dis[j][b] + c + dis[a][k] == dis[j][k]) ok = true;
      }
    }
    if (!ok) ans++;
  }
  cout << ans << endl;
}