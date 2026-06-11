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
  ll n, p;
  cin >> n >> p;
  vl cnt(2, 0);
  rep(i, n) {
    ll a;
    cin >> a;
    cnt[a % 2]++;
  }
  vector<vl> c(51, vl(51, 0));
  rep(i, 51) rep(j, 51) {
    if(j == 0)
      c[i][j] = 1;
    else if(i != 0)
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  ll ans = 0;
  rep(i, cnt[1] + 1) if(i % 2 == p) ans += c[cnt[1]][i];
  ans *= 1LL << cnt[0];
  cout << ans << endl;
}