#include <bits/stdc++.h>
using namespace std;
long long INF=1e16+7;
struct edge{long long to, cost;};
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
    for(int i=1;i<V;i++){
      d[i] = INF;
    }
  }
  void add_edge(long long s, long long t,long long cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }
  void dijkstra(long long s){
    for(int i=0;i<V;i++){
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
  int N;cin>>N;
  graph g(N);
  vector<int>A(N-1);
  vector<int>B(N-1);
  vector<int>C(N-1);
  for(int i=0;i<N-1;i++){
    cin>>A[i]>>B[i]>>C[i];
    g.add_edge(A[i]-1,B[i]-1,C[i]);
    g.add_edge(B[i]-1,A[i]-1,C[i]);
  }
  int Q,K;cin>>Q>>K;
  g.dijkstra(K-1);
  vector<int>x(Q);
  vector<int>y(Q);
  for(int i=0;i<Q;i++){
    cin>>x[i]>>y[i];
    cout<<g.d[x[i]-1]+g.d[y[i]-1]<<endl;
  }
}