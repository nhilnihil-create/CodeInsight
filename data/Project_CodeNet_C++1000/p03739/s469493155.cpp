#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ans = 1e18;
  rep(k, 2) {
    ll sum = 0, now = 0;
    rep(i, n) {
      if(k % 2 == i % 2) {
        if(sum + a[i] <= 0) {
          now += abs(sum) - a[i] + 1;
          sum = 1;
        } else
          sum += a[i];
      } else {
        if(sum + a[i] >= 0) {
          now += abs(sum) + a[i] + 1;
          sum = -1;
        } else
          sum += a[i];
      }
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
}