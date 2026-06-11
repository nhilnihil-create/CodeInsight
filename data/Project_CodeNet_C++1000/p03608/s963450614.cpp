#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//約数列挙(√N)
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
//素因数分解(√N)
map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
//素数テーブル(NloglogN)
vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
//二項係数(K)
template< typename T >
T binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  T ret = 1;
  for(T i = 1; i <= K; ++i) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}
//二項係数テーブル(N^2)
template< typename T >
vector< vector< T > > binomial_table(int N) {
  vector< vector< T > > mat(N + 1, vector< T >(N + 1));
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) mat[i][j] = 1;
      else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }
  return mat;
}
//Gragh template
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
//unionfind
struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};
//DIJKSTRA(ElogV)最短路
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
//prim最小全域木
template< typename T >
T prim(WeightedGraph< T > &g) {
  using Pi = pair< T, int >;
 
  T total = 0;
  vector< bool > used(g.size(), false);
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  que.emplace(0, 0);
  while(!que.empty()) {
    auto p = que.top();
    que.pop();
    if(used[p.second]) continue;
    used[p.second] = true;
    total += p.first;
    for(auto &e : g[p.second]) {
      que.emplace(e.cost, e.to);
    }
  }
  return total;
}
//bellman_ford(VE)単一始点最短路
template< typename T >
vector< T > bellman_ford(Edges< T > &edges, int V, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(V, INF);
  dist[s] = 0;
  for(int i = 0; i < V - 1; i++) {
    for(auto &e : edges) {
      if(dist[e.src] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
    }
  }
  for(auto &e : edges) {
    if(dist[e.src] == INF) continue;
    if(dist[e.src] + e.cost < dist[e.to]) return vector< T >();
  }
  return dist;
}


//memo cout << fixed << setprecision(桁数);//
template< typename T >
vector< T > bellman_forda(Edges< T > &edges, int V, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(V, INF);
  dist[s] = 0;
  for(int i = 0; i < V - 1; i++) {
    for(auto &e : edges) {
      if(dist[e.src] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
    }
  }
    vector<ll> check(V);
    rep(i,V){
  for(auto &e : edges) {
    if(dist[e.src] == INF) continue;
    if(check.at(e.src)==INF)check.at(e.to)=INF;
    if(dist[e.src] + e.cost < dist[e.to])
      check.at(e.to)=INF;
  }
    }
      if(check.at(V-1)==INF)
      return vector< T >();
  return dist;
}
      
int main(){
  int n,m,r;
  cin >> n >> m >> r;
  vector<int> R(r);
  rep(i,r){
    int a;
    cin >> a;
    a--;
    R.at(i)=a;
  }
  ll d[n][n];
  rep(i,n){
    rep(j,n){
      if(i==j)d[i][j]=0;
      else d[i][j]=20000000000000;
    }
  }
  rep(i,m){
    int a,b;
    ll c;
    cin >> a >> b>>c;
    a--;
    b--;
    d[a][b]=c;
    d[b][a]=c;
  }
  rep(k,n){
    rep(i,n){
      rep(j,n){
        if(d[i][k]==20000000000000||d[k][j]==20000000000000)continue;
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  ll ans=20000000000000;
  sort(all(R));
  do{
    ll nowa=0;
    rep(i,r-1)
      nowa+=d[R.at(i)][R.at(i+1)];
    ans=min(ans,nowa);
  }
  while(next_permutation(all(R)));
  cout << ans << endl;
}