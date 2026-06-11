#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;

int main() {
  ll n, k, a[100], sum, ans = INF, mx, q;
  cin >> n >> k;
  rep(i, n) cin >> a[i];

  rep(i, 1 << n) {
    sum = 0;
    q = 1;
    rep(j, n) {
      if (j == 0) mx = a[0];
      if (i & (1 << j) && j != 0) {
        if (mx >= a[j])
          sum += (mx + 1) - a[j], mx++, q++;
        else
          mx = a[j], q++;
      } else {
        if (mx < a[j]) mx = a[j], q++;
      }
    }
    if (q == k) ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
