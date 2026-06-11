#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
  ll n, w;
  cin >> n >> w;
  vector<vector<ll>> q(4);

  ll w1;
  REP(i, n) {
    ll a, b;
    cin >> a >> b;
    if (i == 0) w1 = a;
    a -= w1;
    q[a].push_back(b);
  }

  REP(i, 4) {
    q[i].push_back(0);
    sort(ALL(q[i]), greater<ll>());
  }

  ll ans = 0;
  REP(i, q[0].size() + 1)
  REP(j, q[1].size() + 1) REP(k, q[2].size() + 1) REP(l, q[3].size() + 1) {
    ll sum = i * (w1) + j * (w1 + 1) + k * (w1 + 2) + l * (w1 + 3);

    if (sum > w) continue;

    ll tmp = 0;
    REP(m, i) tmp += q[0][m];
    REP(m, j) tmp += q[1][m];
    REP(m, k) tmp += q[2][m];
    REP(m, l) tmp += q[3][m];

    ans = max(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}