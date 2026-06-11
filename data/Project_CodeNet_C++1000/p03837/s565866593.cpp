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



int main(void){
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  REP(i, n) dist[i][i] = 0;
  vector<tuple<ll, ll, ll>> edge;
  REP(i, m){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
    edge.emplace_back(a, b, c);
  }
  REP(k, n) REP(i, n) REP(j, n) chmin(dist[i][j], dist[i][k] + dist[k][j]);

  ll ans = 0;
  REP(i, m){
    ll a, b, c;
    tie(a, b, c) = edge[i];
    bool ok = false;
    REP(j, n){
      if(dist[j][a] + c == dist[j][b]) ok = true;
    }
    if(!ok) ans++;
  }
  cout << ans << endl;
  return 0;
}