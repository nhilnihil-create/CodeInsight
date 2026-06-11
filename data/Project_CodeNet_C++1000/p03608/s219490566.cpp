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

const ll INF = (ll)(1e18);

int main(void){
  ll N, M, R;
  cin >> N >> M >> R;
  vector<ll> r(R);
  REP(i, R) cin >> r[i], r[i]--;
  sort(ALL(r));
  vector<vector<ll>> g(N, vector<ll>(N, INF));
  REP(i, M){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    g[a][b] = c;
    g[b][a] = c;
  }
  REP(k, N) REP(i, N) REP(j, N) chmin(g[i][j], g[i][k]+g[k][j]);
  ll ans = INF;
  do{
    ll dist = 0;
    REP(i, R-1) dist += g[r[i]][r[i+1]];
    chmin(ans, dist);
  }while(next_permutation(ALL(r)));
  cout << ans << endl;
  return 0;
}