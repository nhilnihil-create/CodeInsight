#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

ll MOD = 1000000007;

int main() {
  ll n;
  cin >> n;

  vi t(n), a(n);
  for (ll i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  vi x1(n, -1), y1(n, 1);

  for (ll i = 0; i < n; i++) {
    if (i == 0 || t[i] > t[i - 1]) {
      x1[i] = y1[i] = t[i];
    } else {
      x1[i] = t[i];
    }
  }

  vi x2(n, -1), y2(n, 1);

  for (ll i = n - 1; i >= 0; i--) {
    if (i == n - 1 || a[i] > a[i + 1]) {
      x2[i] = y2[i] = a[i];
    } else {
      x2[i] = a[i];
    }
  }

  ll ans = 1;
  for (ll i = 0; i < n; i++) {
    ll tmp = min(x1[i], x2[i]) - max(y1[i], y2[i]) + 1;
    if (tmp <= 0) {
      ans = 0;
    } else {
      ans = ans * tmp % MOD;
    }
  }

  cout << ans << endl;
}