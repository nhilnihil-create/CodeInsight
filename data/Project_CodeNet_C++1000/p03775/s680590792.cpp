#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int countDigits(ll n) {
  int ans = 0;
  while (n > 0) {
    n /= 10;
    ++ans;
  }
  return ans;
}

int main() {
  ll n;
  cin >> n;
  int ans = INF;
  for (ll a = 1; a * a <= n; ++a) {
    if (n % a != 0) continue;
    ll b = n / a;
    ans = min(ans, countDigits(max(a, b)));
    // cout << a << " " << b << endl;
  }
  cout << ans << endl;
}
