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
const int INF = 1e9;
const long long INFL = 1LL<<60;

template<typename T> // T: type of cost
struct LCA {
  int n, root, l;
  vector<vector<int>> to;  // グラフ
  vector<vector<T>> co;    // コスト
  vector<int> dep;         // 根からの深さ
  vector<T> costs;         // コスト（距離）
  vector<vector<int>> par;  // ダブリング配列
  LCA(int n):n(n),to(n),co(n),dep(n),costs(n) {
    l = 0;
    while ((1<<l) < n) ++l;
    par = vector<vector<int>>(n+1,vector<int>(l,n));
  }

  // a - b の間にコスト c の辺を張る
  void add_edge(int a, int b, T c=0) {
    to[a].push_back(b); co[a].push_back(c);
    to[b].push_back(a); co[b].push_back(c);
  }
  void dfs(int v, int d=0, T c=0, int p=-1) {
    if (p != -1) par[v][0] = p;
    dep[v] = d;
    costs[v] = c;
    for (int i = 0; i < to[v].size(); ++i) {
      int u = to[v][i];
      if (u == p) continue;
      dfs(u, d+1, c+co[v][i], v);
    }
  }

  // 初期化 _root: 根の頂点番号
  void init(int _root=0) {
    root = _root;
    dfs(root);
    // ダブリングのテーブルを構築する
    for (int i = 0; i < l-1; ++i) {
      for (int v = 0; v < n; ++v) {
        par[v][i+1] = par[par[v][i]][i];
      }
    }
  }
  // LCA
  int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a,b);  // 深いほうが b になるようにしておく
    int gap = dep[b]-dep[a];         // gap ぶん b から登る
    for (int i = l-1; i >= 0; --i) {
      int len = 1<<i;
      if (gap >= len) {
        gap -= len;
        b = par[b][i];
      }
    }
    if (a == b) return a;
    for (int i = l-1; i >= 0; --i) {
      int na = par[a][i];
      int nb = par[b][i];
      if (na != nb) a = na, b = nb;
    }
    return par[a][0];
  }
  int length(int a, int b) {
    int c = lca(a,b);
    return dep[a]+dep[b]-dep[c]*2;
  }
  T dist(int a, int b) {
    int c = lca(a,b);
    return costs[a]+costs[b]-costs[c]*2;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  LCA<ll> lca(n);
  rep(i, n-1) {
    int a, b, c; cin >> a >> b >> c; a--; b--;
    lca.add_edge(a, b, c);
  }
  lca.init(0);

  int q, k;
  cin >> q >> k;
  k--;

  // 全ての頂点の K までの距離を求める
  vector<ll> dist(n, INF);
  rep(i, n) {
    dist[i] = lca.dist(i, k);
  }

  rep(i, q) {
    int x, y; cin >> x >> y; x--; y--;
    cout << dist[x] + dist[y] << endl;
  }

  return 0;
}
