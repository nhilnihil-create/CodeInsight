#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef long long ll;
//typedef pair<ll,ll> P;

//const int INF = 1001001001;
const long long INF = 2e18;
const int MOD = 1000000007;
const double PI=acos(-1);


//-------------------------------------------------ABC35D
struct edge{ll to, cost;};
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
    for(int i=0; i<V; i++){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    for(int i=0; i<V; i++){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> > que; //first:dist from start, second:next v
    que.push(make_pair(0,s));
    while(!que.empty()){
      auto p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(make_pair(d[e.to],e.to));
        }
      }
    }
  }
};

int main() {
    ll N;
    cin >> N;

    graph g1(N),g2(N);

    rep(i,N-1) {
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        g1.add_edge(a,b,c);
        g1.add_edge(b,a,c);
    }

    int Q,K;
    cin >> Q >> K;
    K--;
    g1.dijkstra(K);

    rep(i,Q) {
        ll x,y;
        cin >> x >> y;
        x--,y--;
        cout << g1.d[x]+g1.d[y] << endl;
    }

}