#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

template <typename T>
struct Graph {
  int n;
  vector<vector<pair<int, T>>> to;
  Graph(int n) : n(n), to(n) {}
  void add_edge(int s, int t, T cost=1) {
    to[s].push_back(pair<int, T>(t, cost));
  }
  vector<T> dijkstra(int s, T init) {
    vector<T> d(n, init);
    d[s] = 0;
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>> > pq;
    pq.push(pair<T, int>(0, s));
    while (!pq.empty()) {
      int v = pq.top().second; pq.pop();
      for (auto u : to[v]) {
        if (d[v] + u.second < d[u.first]) {
          d[u.first] = d[v] + u.second;
          pq.push(pair<T, int>(d[u.first], u.first));
        }
      }
    }
    return d;
  }
};

int a[309][309];
using P=pair<ll,ll>;
using Q=pair<P,P>;

int main() {
  int n;
  cin>>n;
  rep(i,n)rep(j,n){
    cin>>a[i][j];
  }
  vector<Q>to;
  rep(i,n)rep(j,i){
    to.push_back(Q(P(a[i][j],i),P(j,0)));
  }
  sort(to.begin(),to.end());
  Graph<ll>g(n);
  ll ans=0;
  for(auto x:to){
    ll dist=x.fi.fi;
    ll i=x.fi.se;
    ll j=x.se.fi;
    auto d=g.dijkstra(i,LLINF);
    if(d[j]<dist){
      cout<<-1<<endl;
      return(0);
    }
    if(d[j]==dist)continue;
    g.add_edge(i,j,dist);
    g.add_edge(j,i,dist);
    ans+=dist;
  }
  cout<<ans<<endl;
  return(0);
}