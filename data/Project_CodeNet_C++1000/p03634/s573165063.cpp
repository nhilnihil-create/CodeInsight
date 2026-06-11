#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

template< typename T >
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

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}


int main() {
    int n;
    cin >> n;
    WeightedGraph<ll> G(n);
    rep (i, n-1) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    int q, k;
    cin >> q >> k;
    auto dist = dijkstra(G, k-1);
    rep (i, q) {
        int a, b;
        cin >> a >> b;
        cout << dist[--a] + dist[--b] << endl;
    }
}
