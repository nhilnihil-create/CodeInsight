#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int n, m; cin >> n >> m;
  int c = abs(n - m);
  if (c > 1) {
    cout << 0;
  } else if (c == 1) {
    // A! * B!
    ll ans = 1;
    for(ll i = 1; i <= n; i++) {
      ans *= i;
      ans %= MOD;
    }
    for(ll i = 1; i <= m; i++) {
      ans *= i;
      ans %= MOD;
    }
    cout << ans;
  } else {
    // A! * B! * 2
    ll ans = 1;
    for(ll i = 1; i <= n; i++) {
      ans *= i;
      ans %= MOD;
    }
    for(ll i = 1; i <= m; i++) {
      ans *= i;
      ans %= MOD;
    }
    ans *= 2;
    ans %= MOD;
    cout << ans;
  }
}
