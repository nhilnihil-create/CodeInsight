#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  vl s(n + 1, 0);
  rep(i, n) {
    ll a;
    cin >> a;
    s[i + 1] = s[i] + a;
  }
  ll ans = 1e18;
  rep(i, n - 1) {
    ll now = abs(s[n] - 2 * s[i + 1]);
    ans = min(ans, now);
  }
  cout << ans << endl;
}