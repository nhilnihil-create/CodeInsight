#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int dp[45][450][450];

int main(void){
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<tuple<int, int, int>> v;
  REP(i, n){
    int a, b, c;
    cin >> a >> b >> c;
    v.emplace_back(a, b, c);
  }
  REP(i, n+1) REP(j, 450) REP(k, 450) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  REP(i, n) REP(j, 400) REP(k, 400){
    int a, b, c;
    tie(a, b, c) = v[i];
    chmin(dp[i+1][j][k], dp[i][j][k]);
    chmin(dp[i+1][j+a][k+b], dp[i][j][k]+c);
  }
  int ans = INF;
  for(ll i = 1; i*ma <= 400 && i*mb <= 400; i++){
    chmin(ans, dp[n][i*ma][i*mb]);
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;
  
  return 0;
}