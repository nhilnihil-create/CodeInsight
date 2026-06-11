#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct edge{ll to, cost;};
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;
  vector<ll> prev;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = LINF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    rep(i,V){
      d[i] = LINF;
    }
    d[s] = 0;
    priority_queue<pll,vector<pll>, greater<pll> > que;
    que.push(pll(0,s));
    prev.assign(V, -1);
    while(!que.empty()){
      pll p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          prev[e.to] = v;
          que.push(pll(d[e.to],e.to));
        }
      }
    }
  }

  vector<int> get_path(int t){ //頂点tへの最短路
    vector<int> path;
    for(; t != -1;t=prev[t]){
        path.push_back(t);
    }

    reverse(path.begin(), path.end());
    return path;
  }
};

int main(){
    int n; cin >> n;
    graph g(n);
    vector<vector<int>> G(n);
    rep(i, n-1){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        g.add_edge(a,b,c);
        g.add_edge(b,a,c);
    }
    int q, k; cin >> q >> k; k--;
    g.dijkstra(k);
    rep(i, q){
        int x, y; cin >> x >> y; x--, y--;
        cout << g.d[x] + g.d[y] << ln;
    }
}
