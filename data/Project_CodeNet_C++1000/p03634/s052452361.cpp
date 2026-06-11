#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000000000000000
typedef long long ll;

struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = mod;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e1, e2;
    e1.to = t, e1.cost = cost;
	e2.to = s, e2.cost = cost;
    G[s].push_back(e1);
    G[t].push_back(e2);
  }

  void dijkstra(ll s){
    rep(i,V){
      d[i] = mod;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};

int main(){
  ll n;
  cin >> n;
  graph g(n);
  rep(i, n-1){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    g.add_edge(a,b,c);
  }
  ll q, k;
  cin >> q >> k;
  k--;
  g.dijkstra(k);
  rep(i, q){
    ll x, y;
    cin >> x >> y;
    x--; y--;
    cout << g.d[x]+g.d[y] << endl;
  }
  return 0;
}
  
