#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

template <typename T>
T gcd(T a, T b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

template <typename T>
T lcm(T a, T b) {
  if (a <= b)
    return b / gcd(a, b) * a;
  else
    return a / gcd(a, b) * b;
}

int main() {
  int n;
  cin >> n;
  vector<ll> t(n);
  for (int i = 0; i < n; i++) cin >> t[i];

  ll ans = 1;
  for (int i = 0; i < n; i++) {
    ans = max(ans, lcm(t[i], ans));
  }
  cout << ans << endl;
}
