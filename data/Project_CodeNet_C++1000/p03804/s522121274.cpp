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
  vs a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  bool ans = false;
  rep(i, n - m + 1) rep(j, n - m + 1) {
    bool now = true;
    rep(di, m) rep(dj, m) if(a[i + di][j + dj] != b[di][dj]) now = false;
    if(now) ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
}