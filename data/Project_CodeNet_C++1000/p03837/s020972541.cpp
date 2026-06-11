#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

const ll INF = 1e18;
vector<vector<ll>> nxt;
// a->bの最短経路復元
// for (ll cur = a; cur != b; cur = nxt[cur][b]) {
//
// }
void warshall_floyd(vector<vector<ll>>& d) {
  ll n = SZ(d);
  nxt = vector<vector<ll>>(n, vector<ll>(n));
  REP(i, n) REP(j, n) { nxt[i][j] = j; }

  REP(i, n) REP(j, n) REP(k, n) if (d[j][k] > d[j][i] + d[i][k]) {
    d[j][k] = d[j][i] + d[i][k];
    nxt[j][k] = nxt[j][i];
  }
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> to(n, vector<ll>(n, INF));

  REP(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    to[a][b] = c;
    to[b][a] = c;
  }
  warshall_floyd(to);
  set<P> st;

  REP(a, n) REP(b, n) {
    for (ll cur = a; cur != b; cur = nxt[cur][b]) {
      ll cv = cur, nv = nxt[cur][b];
      if (cv > nv) {
        swap(cv, nv);
      }
      st.insert({cv, nv});
    }
  }

  cout << m - SZ(st) << endl;
}