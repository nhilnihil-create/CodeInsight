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
  vl c(8, 0);
  ll cnt = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    if(a < 3200)
      c[a / 400] = 1;
    else
      cnt++;
  }
  ll ans = accumulate(all(c), 0);
  cout << max(ans, 1LL) << ' ' << ans + cnt << endl;
}