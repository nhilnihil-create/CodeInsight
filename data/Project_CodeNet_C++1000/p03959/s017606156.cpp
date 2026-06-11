#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<ll> t(n), a(n);

  REP(i, n) { cin >> t[i]; }
  REP(i, n) { cin >> a[i]; }

  // 固定されている値
  vector<ll> checkt(n), checka(n);
  checkt[0] = t[0];
  checka[n - 1] = a[n - 1];

  FOR(i, 1, n) {
    if (t[i - 1] != t[i]) {
      checkt[i] = t[i];
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1] != a[i]) {
      checka[i] = a[i];
    }
  }

  REP(i, n) {
    if (checkt[i] != 0 && checka[i] != 0 && checkt[i] != checka[i]) {
      cout << 0 << endl;
      return 0;
    }
    if (checkt[i] != 0 && a[i] < checkt[i]) {
      cout << 0 << endl;
      return 0;
    }
    if (checka[i] != 0 && t[i] < checka[i]) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  REP(i, n) {
    if (checkt[i] == 0 && checka[i] == 0) {
      ans = (ans * min(a[i], t[i])) % MOD;
    }
  }
  cout << ans << endl;
}
