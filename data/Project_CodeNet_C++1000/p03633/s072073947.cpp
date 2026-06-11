#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  int n;
  cin >> n;
  vector<ll> t(n);
  rep(i, n) cin >> t[i];
  ll ans = t[0];
  for (int i = 1; i < n; ++i) ans = lcm(ans, t[i]);
  cout << ans << endl;
  return 0;
}