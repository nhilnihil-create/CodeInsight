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
  ll n, c, k;
  cin >> n >> c >> k;
  vl t(n);
  rep(i, n) cin >> t[i];
  sort(all(t));
  ll ans = 0, now = -1e18, cnt = 0;
  rep(i, n) {
    if(cnt >= c || t[i] - now > k) {
      ans++;
      now = t[i];
      cnt = 1;
    } else
      cnt++;
  }
  cout << ans << endl;
}