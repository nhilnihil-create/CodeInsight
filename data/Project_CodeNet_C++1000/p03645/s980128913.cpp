#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

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
  int n, m;
  cin >> n >> m;
  graph g(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g.add_edge(a,b,1);
  }
  g.dijkstra(0);
  if(g.d[n-1] == 2) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
