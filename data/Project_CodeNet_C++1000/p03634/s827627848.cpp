#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct edge{long long  to, cost;};
typedef pair<long long,long long> P;

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
        d[i] = 1e15;
    }
  }
  void add_edge(long long s, long long t, long long cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }
  void dijkstra(long long s){
    for(long long i = 0; i < V; i++){
        d[i] = 1e15;
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
    long long n;
    cin >> n;

    graph g(n);

    for(long long i = 0; i < n-1; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a-1, b-1, c);
        g.add_edge(b-1, a-1, c);
    }

    long long q, k;
    cin >> q >> k;

    g.dijkstra(k-1);

    vector<long long> ans;
    for(long long i = 0; i < q; i++){
        long long x, y;
        cin >> x >> y;

        ans.push_back(g.d[x-1]+g.d[y-1]);
    }

    for(long long i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}