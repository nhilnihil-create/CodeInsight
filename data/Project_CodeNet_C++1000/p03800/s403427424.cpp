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
  string s;
  cin >> n >> s;
  rep(k, 4) {
    vl x(n + 1), y(n + 1);
    x[0] = k & 1;
    y[0] = k >> 1 & 1;
    rep(i, n) {
      x[i + 1] = y[i];
      y[i + 1] = x[i] ^ y[i];
      if(s[i] == 'x') y[i + 1] = !y[i + 1];
    }
    if(x[0] != x[n] || y[0] != y[n]) continue;
    rep(i, n) cout << (y[i] ? 'W' : 'S');
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
}