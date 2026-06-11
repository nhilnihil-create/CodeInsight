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

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
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

vector<int> dijkstra(int i, int n, vector<vector<pair<int, int>>> graph) {
  vector<int> d(n, INF);
  d[i] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push(make_pair(0, i));
  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();
    int v = p.second;
    if (d[v] < p.first) {
      continue;
    }
    for (auto x : graph[v]) {
      if (d[x.first] > d[v] + x.second) {
        d[x.first] = d[v] + x.second;
        q.push(pair<int, int>(d[x.first], x.first));
      }
    }
  }
  return d;
}

signed main() {
  int N; 
  cin >> N;

  vector<vector<pair<int, int>>> graph(N);
  REP(i, N-1){
    int u, v, d;
    cin >> u >> v >> d;
    u--; v--;
    graph[u].emplace_back(v, d);
    graph[v].emplace_back(u, d);
  }
  
  int Q, K;
  cin >> Q >> K;

  auto dist = dijkstra(K-1, N, graph);

  while(Q--){
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << dist[x]+dist[y] << "\n";
  }

  return 0;
}