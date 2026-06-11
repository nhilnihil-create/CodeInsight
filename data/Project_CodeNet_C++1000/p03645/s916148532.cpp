#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct edge{long long  to, cost;};
typedef pair<long long,long long> P;

long long INF = 1e15;
struct graph{
  long long V;
  vector<vector<edge> > G;
  vector<long long> d;

  graph(long long n){
      init(n);
  }
  void init(long long n){
    V = n;
    G.resize(V);
    d.resize(V);
    for(long long i = 0; i < V; i++){
        d[i] = INF;
    }
  }
  void add_edge(long long s, long long t, long long cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }
  void dijkstra(long long s){
    for(long long i = 0; i < V; i++){
        d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      long long v = p.second;
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
    long long n, m;
    cin >> n >> m;

    graph g(n);

    for(long long i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b, 1);
        g.add_edge(b, a, 1);
    }

    g.dijkstra(0);

    if(g.d[n-1] <= 2) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");

    return 0;
}