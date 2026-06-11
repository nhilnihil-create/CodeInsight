#include <bits/stdc++.h>
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz size()
#define pb push_back
#define bg begin()
#define ed end()
#define fi first()
#define se second()
using namespace std;
using ll = long long;
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template <typename T>
T sq(T x) {
  return x * x;
}
ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
// cでもc++でも
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

signed main() {
  ll n;
  cin >> n;
  vector<ll> t(n);
  ll ans = 0;
  rep(i, n) {
    cin >> t.at(i);
    if (i == 0) {
      ans = t.at(0);
    } else {
      ans = std::lcm(ans, t.at(i));
    }
  }
  cout << ans << endl;

  return 0;
}

