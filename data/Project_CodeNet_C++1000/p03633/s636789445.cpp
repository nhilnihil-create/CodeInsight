#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(a % b, b);
}
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  int n;
  cin >> n;
  vector<ll> t(n);
  rep(i, n) {
    cin >> t[i];
  }

  ll ans = t[0];
  for (int i = 1; i < n; i++) {
    ans = lcm(ans, t[i]);
  }

  cout << ans << endl;
  
  return 0;
}