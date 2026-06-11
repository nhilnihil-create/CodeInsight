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
  ll n, l;
  cin >> n >> l;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ans = -1;
  rep(i, n - 1) if(a[i] + a[i + 1] >= l) ans = i;
  if(ans >= 0) {
    cout << "Possible" << '\n';
    rep(i, ans) cout << i + 1 << '\n';
    for(ll i = n - 2; i >= ans + 1; i--) cout << i + 1 << '\n';
    cout << ans + 1 << '\n';
  } else
    cout << "Impossible" << endl;
}