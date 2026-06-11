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
  ll a, b, c;
  cin >> a >> b >> c;
  ll ans = 0;
  while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    ll na = b / 2 + c / 2;
    ll nb = c / 2 + a / 2;
    ll nc = a / 2 + b / 2;
    a = na;
    b = nb;
    c = nc;
    ans++;
    if(a == b && b == c) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}