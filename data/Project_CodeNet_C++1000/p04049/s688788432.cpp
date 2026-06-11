// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve
vector<P> vec;

template <typename T>
struct Graph_ {
  int n;
  vector<vector<pair<int, T> > > edge;
  vector<T> dis;
  Graph_(int ns) {
    n = ns;
    edge.resize(n);
    dis.resize(n);
  }
  void dijkstra(int s){
    dijkstra(s, 0);
  }
  T dijkstra(int s, int t){
    // initialize
    fill(dis.begin(), dis.end(), -1);
    vector<bool> used;
    used.resize(n);
    fill(used.begin(), used.end(), false);
    dis[s] = 0;
    // dijkstra
    priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty()){
      pair<T, int> p = q.top(); q.pop();
      int at = p.second;
      T distance = p.first;
      if(used[at])continue;
      used[at] = true;
      for(auto itr = edge[at].begin(); itr != edge[at].end(); ++itr){
        int to = (*itr).first;
        T cost = (*itr).second;
        if(used[to])continue;
        if(dis[to] == -1 || dis[to] > distance + cost){
          q.push(make_pair(distance + cost, to));
          dis[to] = distance + cost;
        }
      }
    }
    return dis[t];
  }
  void adde(int at, int to, T cost){
    edge[at].push_back(make_pair(to, cost));
  }
  [[deprecated("This function takes O(edge[at].size()).")]]
  void remove(int at, int to){
    int index = -1;
    for(int i = 0; i < edge[at].size(); i++){
      if(edge[at][i].first == to){
        index = i;
        break;
      }
    }
    edge[at].erase(edge[at].begin() + index);
  }
};

typedef struct Graph_<int> GraphI;
typedef struct Graph_<ll> GraphL;
typedef struct Graph_<double> GraphD;

int main(int argc, char const* argv[])
{
  int n, k;
  cin >> n >> k;
  GraphI graph(n);
  rep(i, n - 1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph.adde(a, b, 1);
    graph.adde(b, a, 1);
    vec.pb(mk(a, b));
  }
  int res = inf;
  if(k % 2 == 0){
    rep(i, n){
      int tmp = 0;
      graph.dijkstra(i);
      rep(j, n){
        if(graph.dis[j] > k / 2)tmp++;
      }
      res = min(res, tmp);
    }
  }else{
    rep(i, n - 1){
      int tmp = 0;
      int a = vec[i].first;
      int b = vec[i].second;
      graph.dijkstra(a);
      vector<int> dis(n);
      rep(j, n)dis[j] = graph.dis[j];
      graph.dijkstra(b);
      rep(j, n){
        dis[j] = min(dis[j], graph.dis[j]);
        if(dis[j] > (k - 1) / 2)tmp++;
      }
      res = min(res, tmp);
    }
  }
  cout << res << endl;
	return 0;
}
