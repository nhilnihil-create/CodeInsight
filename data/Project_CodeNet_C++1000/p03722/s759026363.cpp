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

vector<ll> to[1000], from[1000];
ll dist[1000][1000];
vector<bool> r1(1000, false), rn(1000, false);

void dfs1(ll v){
  if(r1[v]) return;
  r1[v] = true;
  for(ll u : to[v]){
    dfs1(u);
  }
}

void dfsn(ll v){
  if(rn[v]) return;
  rn[v] = true;
  for(ll u : from[v]){
    dfsn(u);
  }
} 

int main(void){
  ll n, m;
  cin >> n >> m;
  REP(i, m){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    to[a].emplace_back(b);
    from[b].emplace_back(a);
    dist[a][b] = -c;
  }
  dfs1(0);
  dfsn(n-1);
  vector<bool> ok(n, false);
  REP(i, n) ok[i] = r1[i] && rn[i];
  vector<ll> d(n, 1ll<<60);
  d[0] = 0;
  bool upd;
  REP(i, n){
    upd = false;
    REP(v, n){
      if(!ok[v]) continue;
      for(ll u : to[v]){
        if(!ok[u]) continue;
        if(d[v] + dist[v][u] < d[u]){
          d[u] = d[v] + dist[v][u];
          upd = true;
        }
      }
    }
    if(!upd) break;
  }
  if(upd) cout << "inf" << endl;
  else cout << -d[n-1] << endl;
  return 0;
}