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
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.size();
  rep(i, n - 1) {
    ll need = 'z' - s[i] + 1;
    if(s[i] == 'a' || need > k) continue;
    s[i] = 'a';
    k -= need;
  }
  k %= 26;
  ll m = s[n - 1] + k;
  if(m > 'z') m -= 26;
  s[n - 1] = char(m);
  cout << s << endl;
}