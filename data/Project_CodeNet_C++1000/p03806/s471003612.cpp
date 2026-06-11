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


signed main() {
  int N, ma, mb; 
  cin >> N >> ma >> mb;

  vector<int> A(N), B(N), C(N);
  REP(i, N) cin >> A[i] >> B[i] >> C[i];

  int MAX = 500;
  int dp[N+1][MAX][MAX];
  REP(i, N+1) REP(j, MAX) REP(k, MAX) dp[i][j][k] = INF;
  dp[0][0][0] = 0;

  REP(i, N) REP(j, MAX) REP(k, MAX){
    chmin(dp[i+1][j][k], dp[i][j][k]);
    if(j+A[i] < MAX && k+A[i] < MAX){
      chmin(dp[i+1][j+A[i]][k+B[i]], dp[i][j][k]+C[i]);
    }
  }

  int ans = INF;
  int i = 1;
  while(i*ma < MAX && i*mb < MAX){
    chmin(ans, dp[N][i*ma][i*mb]);
    i++;
  }

  if(ans == INF) ans = -1;
  cout << ans << "\n";

  return 0;
}