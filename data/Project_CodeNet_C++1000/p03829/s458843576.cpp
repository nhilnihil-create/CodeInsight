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

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  REP(i, n) cin >> x[i];

  ll ans = 0;
  FOR(i, 1, n) { ans += min(a * (x[i] - x[i - 1]), b); }
  cout << ans << endl;
  return 0;
}