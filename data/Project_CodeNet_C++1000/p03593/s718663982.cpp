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
  ll h, w;
  cin >> h >> w;
  map<char, ll> mp;
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    mp[c]++;
  }
  bool ans;
  if(h == 1 || w == 1) {
    ll cnt = 0;
    for(auto v : mp)
      if(v.second % 2) cnt++;
    if(cnt >= 2)
      ans = false;
    else if(h == 1)
      ans = cnt % 2 == w % 2;
    else
      ans = cnt % 2 == h % 2;
  } else {
    ll c = 0;
    if(h % 2) c += w;
    if(w % 2) c += h;
    bool odd = h % 2 && w % 2;
    if(odd) c -= 2;
    ll c2 = 0, c1 = 0;
    for(auto v : mp) {
      ll k = v.second;
      if(k % 4 == 0)
        continue;
      else if(k % 2 == 0)
        c2++;
      else
        c1++;
    }
    ans = true;
    if(c1 > odd || c2 * 2 > c) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}