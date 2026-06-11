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
  ll n, k;
  cin >> n >> k;
  vl a(n + 1, 0), b(n + 1, 0);
  rep(i, n) {
    ll x;
    cin >> x;
    a[i + 1] = a[i] + x;
    b[i + 1] = b[i] + max(0LL, x);
  }
  ll ans = -1e18;
  rep(i, n - k + 1) {
    ll now = max(0LL, a[k + i] - a[i]);
    now += b[i] + b[n] - b[k + i];
    ans = max(ans, now);
  }
  cout << ans << endl;
}