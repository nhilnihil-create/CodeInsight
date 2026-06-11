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
  ll n, m;
  cin >> n >> m;
  vl red(n, 0), cnt(n, 1);
  red[0] = 1;
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    cnt[x]--;
    cnt[y]++;
    if(red[x] == 1) red[y] = 1;
    if(cnt[x] == 0) red[x] = 0;
  }
  ll ans = 0;
  rep(i, n) if(red[i] == 1) ans++;
  cout << ans << endl;
}