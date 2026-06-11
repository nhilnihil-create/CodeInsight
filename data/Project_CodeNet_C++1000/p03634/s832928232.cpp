#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

using Graph = vector<vector<int>>;
vector<bool> seen;
map<int, ll> k_dists;
map<pair<int, int>, ll> dists;

void dfs(const Graph &G, int v, ll dist) {
  seen[v] = true;  // v を訪問済にする
  // v から行ける各頂点 next_v について
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;  // next_v が探索済だったらスルー
    k_dists[next_v] = dist + dists[make_pair(v, next_v)];
    dfs(G, next_v, dist + dists[make_pair(v, next_v)]);  // 再帰的に探索
  }
}
int main() {
  int n;
  cin >> n;
  Graph G(n);
  REP(i, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    dists[make_pair(a, b)] = c;
    dists[make_pair(b, a)] = c;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int q, k;
  cin >> q >> k;
  k--;

  seen.assign(n + 1, false);
  dfs(G, k, 0);

  REP(i, q) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << k_dists[x] + k_dists[y] << endl;
  }
}