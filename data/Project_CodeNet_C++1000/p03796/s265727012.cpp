#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  ll ans = 1;
  repe(i, 1, N) ans = (ans * i) % MOD;
  cout << ans << endl;
  return 0;
}
