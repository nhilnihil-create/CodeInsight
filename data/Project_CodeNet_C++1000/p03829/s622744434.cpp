#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  ll n, a, b, p;
  cin >> n >> a >> b;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i) {
      ans += min((x - p) * a, b);
    }
    p = x;
  }
  cout << ans << endl;
  return 0;
}
