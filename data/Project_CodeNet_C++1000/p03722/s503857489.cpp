#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

vector<bool> ok;

bool bellmanford(int s, int N, vector<vector<pair<int, int>>>& graph, vector<int>& d){
  d = vector<int>(N, INF);
  d[s] = 0;
  for(int i = 0; i < N; i++){
    for(int v = 0; v < N; v++){
      if(!ok[v]) continue;
      for(int k = 0; k < (int)graph[v].size(); k++){
        pair<int, int> e = graph[v][k];
        if(d[v] != INF && d[e.first] > d[v] + e.second){
          d[e.first] = d[v] + e.second;
          if(i == N-1) return true;
        }
      }
    }
  }
  return false;
}

signed main() {
  int N, M; 
  cin >> N >> M;

  vector<vector<int>> back(N);
  vector<vector<pair<int, int>>> graph(N);
  REP(i, M){
    int u, v, d;
    cin >> u >> v >> d;
    u--; v--;
    back[v].emplace_back(u);
    graph[u].emplace_back(v, -d);
  }

  ok.resize(N, false);
  ok[N-1] = true;

  queue<int> q;
  q.push(N-1);

  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int u : back[v]){
      if(ok[u]) continue;
      ok[u] = true;
      q.push(u);
    }
  }

  vector<int> dist(N);
  if(bellmanford(0, N, graph, dist)){
    cout << "inf" << "\n";
  }else{
    cout << -dist[N-1] << "\n";
  }

  return 0;
}