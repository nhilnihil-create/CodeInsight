#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

void solve() {
  ll x, ans = 0, count = 0;
  cin >> x;
  ans += x / 11 * 2;
  count = (x / 11) * 11;
  if (x % 11 != 0) {
    ans += 1;
    count += 6;
    if (6 < x % 11) {
      ans += 1;
      count += 5;
    }
  }
  cout << ans << endl;
}

signed main() {
  solve();

  return 0;
}
