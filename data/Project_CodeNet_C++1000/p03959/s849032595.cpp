#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> t(n), a(n), nt(n), na(n);
  rep(i, n) cin >> t[i];
  rep(i, n) cin >> a[i];
  nt[0] = 1;
  na[n - 1] = 1;
  repi(i, 1, n) {
    if (t[i] > t[i - 1])
      nt[i] = 1;
    else if (t[i] == t[i - 1])
      nt[i] = t[i];
    else {
      cout << 0 << endl;
      return 0;
    }
    if (a[n - 1 - i] > a[n - i])
      na[n - 1 - i] = 1;
    else if (a[n - 1 - i] == a[n - i])
      na[n - 1 - i] = a[n - 1 - i];
    else {
      cout << 0 << endl;
      return 0;
    }
  }
  vector<ll> c(n);
  rep(i, n) {
    if (nt[i] == 1 || na[i] == 1) {
      if (nt[i] == 1 && na[i] == 1) {
        if (t[i] == a[i])
          c[i] = 1;
        else {
          cout << 0 << endl;
          return 0;
        }
      } else if (nt[i] == 1 && na[i] != 1) {
        if (t[i] <= a[i])
          c[i] = 1;
        else {
          cout << 0 << endl;
          return 0;
        }
      } else {
        if (a[i] <= t[i])
          c[i] = 1;
        else {
          cout << 0 << endl;
          return 0;
        }
      }
    } else {
      c[i] = min(nt[i], na[i]);
    }
  }
  ll ans = 1;
  rep(i, n) ans = ans * c[i] % mod;
  cout << ans << endl;
  return 0;
}
