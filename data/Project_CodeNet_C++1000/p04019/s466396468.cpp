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
  cin >> s;
  map<char, ll> mp;
  rep(i, s.size()) mp[s[i]]++;
  bool ans = true;
  if(mp['N'] > 0 && mp['S'] == 0) ans = false;
  if(mp['S'] > 0 && mp['N'] == 0) ans = false;
  if(mp['W'] > 0 && mp['E'] == 0) ans = false;
  if(mp['E'] > 0 && mp['W'] == 0) ans = false;
  cout << (ans ? "Yes" : "No") << endl;
}