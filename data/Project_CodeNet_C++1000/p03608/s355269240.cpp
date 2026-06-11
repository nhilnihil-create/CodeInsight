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
void init(ll V, vvll& cost) {
  cost = vvll(V, vll(V, INF));
  rep(i, V) {
    // 自分自身へ移動するコストは0
    cost[i][i] = 0;
  }
}

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

  ll n, m, r;
  cin >> n >> m >> r;

  vll route(r);
  rep(i, r) {
    cin >> route[i];
  }

  // 最終的にiからjの最小コストはcost[i][j]となる。
  vvll cost;
  init(n + 1, cost);

  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    cost[a][b] = c;
    cost[b][a] = c;
  }

  warshall_floyd(n + 1, cost);

  sort(all(route));

  ll ans = INF;

  do {
    ll c = 0;
    REP(i, r) {
      c += cost[route[i]][route[i - 1]];
    }
    chmin(ans, c);
  } while (next_permutation(all(route)));

  cout << ans << endl;

  return 0;
}
