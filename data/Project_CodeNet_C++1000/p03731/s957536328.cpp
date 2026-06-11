#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N, T;
  cin >> N >> T;
  vector<ll> t(N);
  cin >> t[0];
  ll ans = 0;
  rep(i, 1, N) {
    cin >> t[i];
    ll diff = t[i] - t[i - 1];
    if (diff <= T) {
      ans += diff;
    } else {
      ans += T;
    }
  };
  ans += T;

  cout << ans << endl;

  return 0;
}
