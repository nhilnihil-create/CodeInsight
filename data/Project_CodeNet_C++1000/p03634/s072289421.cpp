#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

const ll INF = LLONG_MAX;

struct Edge {//グラフ
    ll to, cap, rev;
    Edge(ll _to, ll _cap, ll _rev) {
        to = _to; cap = _cap; rev = _rev;
    }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));//最小カット計算時逆辺は0にする
}

void Dijkstra(Graph& G, ll s, vector<ll>& d) {//O(|E|log|V|)
    d.resize(G.size());
    rep(i, d.size())d[i] = INF;
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        P a = q.top();
        q.pop();
        if (d[a.second] < a.first)continue;
        rep(i, G[a.second].size()) {
            Edge e = G[a.second][i];
            if (d[e.to] > d[a.second] + e.cap) {
                d[e.to] = d[a.second] + e.cap;
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}

//グラフ構築例
int main(){
  ll n;
  cin>>n;
  Graph g(n);
  rep(i,n-1){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    add_edge(g,a,b,c,true,c);
  }
  ll q,k;
  cin>>q>>k;
  k--;
  vector<ll> d(n);
  Dijkstra(g,k,d);
  rep(i,q){
    int x,y;
    cin>>x>>y;
    x--;y--;
    cout<<d[x]+d[y]<<endl;
  }
}