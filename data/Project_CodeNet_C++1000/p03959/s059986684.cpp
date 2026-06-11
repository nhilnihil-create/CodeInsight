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
  vector<ll> t(n), a(n);
  REP(i, n) cin >> t[i];
  REP(i, n) cin >> a[i];

  vector<bool> tr(n, true), ar(n, true);

  tr[0] = ar[n - 1] = false;
  FOR(i, 1, n) {
    if (t[i - 1] != t[i]) {
      tr[i] = false;
    }
  }

  FORR(i, n - 2, 0) {
    if (a[i + 1] != a[i]) {
      ar[i] = false;
    }
  }

  ll ans = 1;
  REP(i, n) {
    if (tr[i] && ar[i]) {
      ans *= min(t[i], a[i]);
      ans %= MOD;
    } else if (!tr[i] && ar[i]) {
      if (t[i] > a[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else if (tr[i] && !ar[i]) {
      if (a[i] > t[i]) {
        cout << 0 << endl;
        return 0;
      }
    } else {
      if (t[i] != a[i]) {
        cout << 0 << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;
  return 0;
}