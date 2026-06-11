#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int s = (n % 2) + 1;
  bool pos = true;
  if (n % 2) {
    if (a[0] != 0) {
      cout << 0 << '\n';
      return 0;
    }
    for (int i = 1; i < n; i++) {
      if (i != 1 && i % 2 == 1) {
        s += 2;
      }

      if (a[i] != s) {
        pos = false;
        break;
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (i != 0 && i % 2 == 0) {
        s += 2;
      }
      if (a[i] != s) {
        pos = false;
        break;
      }
    }
  }
  if (pos) {
    ll ans = 1;
    for (int i = 0; i < n/2; i++) {
      ans = (ans * 2) % mod;
    }
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}
