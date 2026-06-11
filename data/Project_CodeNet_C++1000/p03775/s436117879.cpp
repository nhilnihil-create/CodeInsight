#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

template <typename T>
vector<T> factors(T n) {
  vector<T> ret;
  for (T i = 1; i * i <= n; i++) {
    if (n % i == 0) ret.push_back(i);
  }
  return ret;
}

int digits(ll n) {
  int ret = 1;
  while (n >= 10) {
    ret++;
    n /= 10;
  }
  return ret;
}

int f(ll a, ll b) { return max(digits(a), digits(b)); }

int main() {
  ll n;
  cin >> n;

  int ans = 1000;
  auto fs = factors(n);
  for (ll a : fs) {
    ll b = n / a;
    ans = min(ans, f(a, b));
  }
  cout << ans << endl;
}
