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
  ll mx = 1e5 + 10;
  ll n;
  cin >> n;
  vl a(mx, 0);
  rep(i, n) {
    ll c;
    cin >> c;
    a[c]++;
  }
  vl sum(mx + 1, 0);
  rep(i, mx) sum[i + 1] = sum[i] + a[i];
  ll ans = 0;
  rep(i, mx - 3) ans = max(ans, sum[i + 3] - sum[i]);
  cout << ans << endl;
}