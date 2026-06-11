#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n - 1) {
    if (a[i] + a[i + 1] > x) {
      ll tmp = a[i] + a[i + 1] - x;
      ans += tmp;
      a[i + 1] = max((ll)0, a[i + 1] - tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
