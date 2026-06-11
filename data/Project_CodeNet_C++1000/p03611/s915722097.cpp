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
  vl c(1e5 + 1, 0);
  rep(i, n) {
    ll a;
    cin >> a;
    c[a]++;
  }
  ll ans = 0;
  rep2(i, 1, 1e5) {
    ll now = c[i - 1] + c[i] + c[i + 1];
    ans = max(ans, now);
  }
  cout << ans << endl;
}