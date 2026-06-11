#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>

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

int ans = INF;
int N, M, R; 
vector<int> r(10);
vector<bool> visited(10, false);
vector<vector<int>> dist(300, vector<int>(300, INF));

void dfs(int c, int p, int d){
  if(c == R){
    chmin(ans, d);
    return;
  }
  REP(i, R){
    if(visited[i]) continue;
    visited[i] = true;
    if(p != -1) dfs(c+1, i, d+dist[r[i]][r[p]]);
    else dfs(c+1, i, 0);
    visited[i] = false;
  }
}

signed main() {
  cin >> N >> M >> R;

  REP(i, R){
    cin >> r[i];
    r[i]--;
  }

  REP(i, N) dist[i][i] = 0;
  REP(i, M){
    int u, v, d;
    cin >> u >> v >> d;
    u--; v--;
    dist[u][v] = d;
    dist[v][u] = d;
  }

  REP(k, N) REP(i, N) REP(j, N){
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }

  dfs(0, -1, 0);
  cout << ans << endl;

  return 0;
}