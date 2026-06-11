#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int d(ll a) {
  int res = 0;
  while (a) {
    a /= 10;
    ++res;
  }
  return res;
}

int f(ll a, ll b) {
  return max(d(a), d(b));
}

int main() {
  ll n;
  cin >> n;
  int ans = 100;
  for (ll a = 1; a * a <= n; ++a) {
    if (n % a) continue;
    ll b = n / a;
    ans = min(ans, f(a, b));
  }
  cout << ans << endl;
  return 0;
}