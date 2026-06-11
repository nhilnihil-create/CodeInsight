#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const ll mod = 1e9 + 7;

int main() {
  int n, a;
  cin >> n;
  vector<int> num(n, 0);
  rep(i, 0, n) {
    cin >> a;
    num[a]++;
  }

  ll ans = 1;

  // 奇数個
  if (n % 2 == 1) {
    if (num[0] != 1) {
      cout << 0 << endl;
      return 0;
    }

    for (int i = 2; i < n; i += 2) {
      if (num[i] != 2) {
        cout << 0 << endl;
        return 0;
      }
      ans *= 2;
      ans %= mod;
    }
    cout << ans << endl;
    return 0;
  }

  // 偶数個
  if (n % 2 == 0) {
    for (int i = 1; i < n; i += 2) {
      if (num[i] != 2) {
        cout << 0 << endl;
        return 0;
      }
      ans *= 2;
      ans %= mod;
    }
    cout << ans << endl;
    return 0;
  }

  return 0;
}
