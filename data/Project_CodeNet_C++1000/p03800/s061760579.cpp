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
  rep(i, 2) rep(j, 2) {
    ll a = i, b = j;
    vl ans(n + 1, 0);
    ans[0] = b;
    rep(k, n) {
      if(s[k] == 'o')
        ans[k + 1] = a ^ b;
      else
        ans[k + 1] = !(a ^ b);
      a = b;
      b = ans[k + 1];
    }
    if(i != ans[n - 1] || j != ans[n]) continue;
    rep(k, n) cout << (ans[k] ? "W" : "S");
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
}