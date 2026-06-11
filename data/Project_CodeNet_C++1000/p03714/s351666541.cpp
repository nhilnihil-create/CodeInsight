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
  ll n;
  cin >> n;
  vector<ll> m(n), sl(n + 1, 0), sr(n + 1, 0);
  priority_queue<ll> qr;
  priority_queue<ll, vector<ll>, greater<ll>> ql;
  REP(i, n) {
    ll l;
    cin >> l;
    sl[0] += l;
    ql.push(l);
  }
  REP(i, n) cin >> m[i];
  REP(i, n) {
    ll r;
    cin >> r;
    sr[0] += r;
    qr.push(r);
  }

  FOR(i, 1, n + 1) {
    sl[i] = sl[i - 1];
    sl[i] += m[i - 1];
    ql.push(m[i - 1]);
    sl[i] -= ql.top();
    ql.pop();
  }
  reverse(ALL(m));
  FOR(i, 1, n + 1) {
    sr[i] = sr[i - 1];
    sr[i] += m[i - 1];
    qr.push(m[i - 1]);
    sr[i] -= qr.top();
    qr.pop();
  }

  ll ans = -INF;
  REP(i, n + 1) { ans = max(ans, sl[i] - sr[n - i]); }

  cout << ans << endl;
  return 0;
}