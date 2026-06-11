#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n; cin >> n;
  vll t(n), a(n);
  REP(i, n) cin >> t.at(i);
  REP(i, n) cin >> a.at(i);
  vll high(n, 0);
  ll ans = 1;
  rep(i, 1, n-1) {
    if (t.at(i) != t.at(i-1)) {
      if (a.at(i) != a.at(i+1) && t.at(i) != a.at(i)) {
        ans = 0; break;
      } else if (a.at(i) < t.at(i)) {
        ans = 0; break;
      }
    } else if (a.at(i) != a.at(i+1)) {
      if (t.at(i) != t.at(i-1) && t.at(i) != a.at(i)) {
        ans = 0; break;
      } else if (t.at(i) < a.at(i)) {
        ans = 0; break;
      }
    } else {
      ans *= min(a.at(i), t.at(i));
      ans %= MOD;
    }
  }
  if (a.at(0) != t.at(n-1)) cout << 0 << endl;
  else cout << ans << endl;
  return 0;
}
