#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
//typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//const ll INF = 1e18;

//テンプレート
//辺の構築
template< typename T = ll >
struct Edge {
  ll from, to;
  T cost;
  ll idx;

  Edge() = default;

  Edge(ll from, ll to, T cost = 1, ll idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator ll() const { return to; }
};

template< typename T = ll >
struct Graph {
  vector< vector< Edge< T > > > g;
  ll es;

  Graph() = default;

  explicit Graph(ll n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(ll from, ll to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(ll from, ll to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(ll M, ll padding = -1, bool weighted = false, bool directed = false) {
    for(ll i = 0; i < M; i++) {
      ll a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

template< typename T = ll >
using Edges = vector< Edge< T > >;



/**
 * @brief Bellman-Ford(単一始点最短路)
 * 負の辺がある時にも使える
 */
template< typename T >
vector< T > bellman_ford(const Edges< T > &edges, ll V, ll s) {
  const auto INF = 1e16;
  vector< T > dist(V, INF);
  dist[s] = 0;
  for(ll i = 0; i < V - 1; i++) {
    for(auto &e : edges) {
      if(dist[e.from] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
    }
  }
  for(auto &e : edges) {
    if(dist[e.from] == INF) continue;
    if(dist[e.from] + e.cost < dist[e.to]);
  }
  return dist;
}

template< typename T >
bool bellman_ford2(const Edges< T > &edges, ll V, ll s,vector<ll> ans) {
  const auto INF = 1e16;
  vector< T > dist(V);
  rep(i,V){
      dist[i]=ans[i];
  }
  for(ll i = 0; i < V - 1; i++) {
    for(auto &e : edges) {
      if(dist[e.from] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
      if(dist[V-1]!=ans[V-1])return false;
    }
  }
  return true;
}

int main(){
    ll n,m;
    cin >> n >> m;
    Edges<ll>e(m);
    rep(i,m){
        ll a,b;ll c;
        cin >> a >> b >> c;
        a--;b--;
        e[i]={a,b,-c};
    }
    auto ans = bellman_ford(e,n,0);
    if(ans.size()==0||(!bellman_ford2(e,n,0,ans))){
        cout << "inf" << endl;
    }
    else{
        cout << -ans[n-1] << endl;
    }
    return 0;
}
