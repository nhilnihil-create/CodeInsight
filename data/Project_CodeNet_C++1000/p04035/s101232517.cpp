#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double



////////////////////////////////////////////////////////////////////

template<typename T>
struct edge {
  int to, from;T cost;
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
template<typename T>
using edges = vector<edge<T>>;
template<typename T>
using graph = vector<edges<T>>;
template<typename T>
using matrix = vector<vector<T>>;

template<typename T>
bool compByCost(const edge<T>& left, const edge<T>& right){
  return left.cost < right.cost; 
}

template<typename T>
vector<T> dijkstra(int s, graph<T> &g){
  vector<T> dist(g.size()+10, INF);dist[s] = 0;
  priority_queue<P, vector<P>, greater<P>> que;que.push(P(0,s));
  while(!que.empty()){
    P p = que.top();que.pop();
    int v = p.second;
    if(dist[v] < p.first)continue;
    rep(i, g[v].size()){
      edge<T> e = g[v][i];
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
  return dist;
}

#define dijkstra dijkstra<int>

////////////////////////////////////////////////////////////////////i

int n,l,a[110000];
signed main(){
  cin>>n>>l;rep(i,n)cin>>a[i];
  rep(i,n-1){
    if(a[i]+a[i+1] < l)continue;
    cout << "Possible" << endl;
    repd(j,1,i+1){
      cout << j << endl;
    }
    rep(j, n-i-1){
      cout << n-j-1 << endl;
    }
    return 0;
  }

  cout << "Impossible" << endl;
}
