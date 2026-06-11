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
  ll n, k;
  cin >> n >> k;
  bitset<30> v;
  rep(i, 30) if(k >> i & 1) v.set(i, 1);
  vl b(n);
  vector<bitset<30>> bs(n);
  rep(i, n) {
    ll a;
    cin >> a >> b[i];
    rep(j, 30) if(a >> j & 1) bs[i].set(j, 1);
  }
  ll ans = 0;
  for(ll x = 29; x >= 0; x--) {
    if(!v.test(x) && x > 0) continue;
    ll now = 0;
    rep(i, n) {
      bool ok = true;
      for(ll j = 29; j >= x; j--)
        if(!v.test(j) && bs[i].test(j)) ok = false;
      if(bs[i].test(x) && x > 0) ok = false;
      if(ok) now += b[i];
    }
    ans = max(ans, now);
    // cout << x << ' ' << ans << endl;
  }
  cout << ans << endl;
}