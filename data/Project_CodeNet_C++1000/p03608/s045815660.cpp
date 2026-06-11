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
void warshall_floyd(vector<vector<ll>>& d) {
  ll n = SZ(d);
  REP(i, n) REP(j, n) REP(k, n) if (d[j][k] > d[j][i] + d[i][k]) {
    d[j][k] = d[j][i] + d[i][k];
  }
}

int main() {
  ll n, m, r;
  cin >> n >> m >> r;
  vector<ll> a(r);
  REP(i, r) {
    cin >> a[i];
    a[i]--;
  }
  vector<vector<ll>> to(n, vector<ll>(n, INF));
  REP(i, n) { to[i][i] = 0; }
  REP(i, m) {
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    to[u][v] = c;
    to[v][u] = c;
  }
  warshall_floyd(to);
  ll ans = INF;
  sort(ALL(a));
  do {
    ll t = 0;
    REP(i, r - 1) { t += to[a[i]][a[i + 1]]; }
    ans = min(ans, t);
  } while (next_permutation(ALL(a)));
  cout << ans << endl;
}