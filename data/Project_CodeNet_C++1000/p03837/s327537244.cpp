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


signed main() {
  int N, M; 
  cin >> N >> M;

  vector<int> u(M), v(M), d(M);
  vector<vector<int>> dist(N, vector<int>(N, INF));
  REP(i, N) dist[i][i] = 0;
  REP(i, M){
    cin >> u[i] >> v[i] >> d[i];
    u[i]--; v[i]--;
    dist[u[i]][v[i]] = d[i];
    dist[v[i]][u[i]] = d[i];
  }

  REP(k, N) REP(i, N) REP(j, N){
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }

  int ans = 0;
  REP(k, M){
    bool flag = false;
    REP(i, N) REP(j, N){
      if(dist[i][j] == dist[i][u[k]]+d[k]+dist[v[k]][j]) flag = true;
    }
    if(flag) ans++;
  }

  cout << M-ans << endl;

  return 0;
}