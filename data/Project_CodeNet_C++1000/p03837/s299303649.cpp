#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
const long long INF = 1LL << 60;

// Warshall-Floyd
// O(V^3)
void warshall_floyd(ll V, vvll& cost) {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, m;
  cin >> n >> m;

  vll a(m), b(m), c(m);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
  }

  // 最終的にiからjの最小コストはcost[i][j]となる。
  vvll cost = vvll(n + 1, vll(n + 1, INF));
  rep(i, n + 1) {
    // 自分自身へ移動するコストは0
    cost[i][i] = 0;
  }

  rep(i, m) {
    cost[a[i]][b[i]] = c[i];
    cost[b[i]][a[i]] = c[i];
  }

  warshall_floyd(n + 1, cost);

  ll ans = 0;

  rep(i, m) {
    if (cost[a[i]][b[i]] != c[i]) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
