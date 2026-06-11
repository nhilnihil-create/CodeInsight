#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////
const ll inf = 1LL<<60;

template<typename T>
struct Dijkstra {
  int n;
  WeightedGraph<T> es;
  vector<T> dist;
  vector<int> prev;
  Dijkstra(int _n, WeightedGraph<T> _es) {
    init(_n, _es);
  }
  void init(int _n, WeightedGraph<T> _es) {
    n = _n; es = _es;
  }
  void reset() {
    dist.assign(n, inf);
    prev.assign(n, -1);
  }
  void run(int s) {
    reset();
    dist[s] = 0;
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, s));
    while (!pq.empty()) {
      P p = pq.top(); pq.pop();
      T v = p.second;
      if (dist[v] < p.first) continue;
      for (int i=0; i<(int)es[v].size(); i++) {
        edge<T> e = es[v][i];
        if (dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          pq.push(P(dist[e.to], e.to));
          prev[e.to] = v;
        }
      }
    }
  }
  vector<int> getpath(int t) {
    vector<int> path;
    if (dist[t] == inf) return path;
    for (; t!=-1; t=prev[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
  }
};

int main()
{
  int n; cin>>n;
  WeightedGraph<ll> g(n);
  rep(i, n-1) {
    int a,b,c; cin>>a>>b>>c; a--; b--;
    g[a].push_back(edge<ll>(b, c));
    g[b].push_back(edge<ll>(a, c));
  }
  int q,k; cin>>q>>k; k--;
  Dijkstra<ll> dij(n, g);
  dij.run(k);
  vector<ll> ans(q);
  rep(i, q) {
    int x, y; cin>>x>>y; x--; y--;
    ans[i] = dij.dist[x] + dij.dist[y];
  }
  rep(i, q) cout << ans[i] << endl;

  return 0;
}
