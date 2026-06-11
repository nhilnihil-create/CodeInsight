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
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

void solve() {
  int x, a, b;
  string ans = "";
  cin >> x >> a >> b;
  if (b <= a) {
    ans = "delicious";
  } else if (b <= a + x) {
    ans = "safe";
  } else if (b > a + x) {
    ans = "dangerous";
  }

  cout << ans << endl;
}

signed main() {
  solve();

  return 0;
}