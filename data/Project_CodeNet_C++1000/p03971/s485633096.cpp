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
  ll n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  ll cnt = 0, cb = 0;
  rep(i, n) {
    bool ans = true;
    if(s[i] == 'a') {
      if(cnt >= a + b)
        ans = false;
      else
        cnt++;
    } else if(s[i] == 'b') {
      if(cnt >= a + b || cb >= b)
        ans = false;
      else
        cnt++;
      cb++;
    } else
      ans = false;
    cout << (ans ? "Yes" : "No") << '\n';
  }
}