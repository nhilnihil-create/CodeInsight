#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n, K;
  cin >> n >> K;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ans = 1e18;
  rep(k, 1 << n) {
    ll cnt = 0, yen = 0, mh = 0;
    rep(i, n) {
      if(k >> i & 1) {
        yen += max(0LL, mh - a[i] + 1);
        mh = max(mh + 1, a[i]);
        cnt++;
      } else if(mh < a[i]) {
        mh = a[i];
        cnt++;
      }
    }
    if(cnt >= K) ans = min(ans, yen);
  }
  cout << ans << endl;
}