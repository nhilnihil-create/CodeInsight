#include <bits/stdc++.h>
//#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<double,double> P;
const ll INF = 1e18;
const int MOD = 1000000007;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

template<typename T>
struct edge {
  int to, from;T cost;
  edge(int to) : from(-1), to(to), cost(-1) {}
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
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,int>>> que;que.push(P(0,s));
  while(!que.empty()){
    pair<T,int> p = que.top();que.pop();
    int v = p.second;
    if(dist[v] < p.first)continue;
    rep(i, g[v].size()){
      edge<T> e = g[v][i];
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        que.push(make_pair(dist[e.to], e.to));
      }
    }
  }
  return dist;
}

#define dijkstra dijkstra<double>


int n,m;deque<int> g[110000],ans;
bool inc[110000];

void dfs(int x, bool b){
  if(!inc[x]){
    if(!b)ans.push_back(x);
    else ans.push_front(x);
  }
  inc[x] = true;
  int c = true;
  rep(i,g[x].size()){
    if(!inc[g[x][i]]){
      dfs(g[x][i], b);
      return;
    }
  }
}

signed main(){
  cin>>n>>m;int s;
  rep(i,m){
    int a, b;cin>>a>>b;a--;b--;s = a;
    g[a].push_back(b);g[b].push_back(a);
  }
  ans.push_back(s);inc[s] = true;
  dfs(g[s][0], false);
  dfs(s, true);
  cout << ans.size() << endl;
  rep(i,ans.size())cout << ans[i]+1 << (ans.size()-1 == i ? "\n" : " ");
}
