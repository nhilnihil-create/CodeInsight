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
  ll n, x, ans = 0;
  cin >> n >> x;
  vl a(n);
  rep(i, n) cin >> a[i];
  rep2(i, 1, n) {
    ll now = a[i - 1] + a[i];
    ll d = now - x;
    if(d > 0) {
      ans += d;
      a[i] = max(a[i] - d, 0LL);
    }
  }
  cout << ans << endl;
}