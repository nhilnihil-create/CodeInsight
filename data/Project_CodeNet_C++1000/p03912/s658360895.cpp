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
  map<ll, ll> mp, mx, my;
  rep(i, n) {
    ll x;
    cin >> x;
    mp[x]++;
  }
  for(auto v : mp) {
    ll k = v.first;
    ll num = v.second;
    my[k % m] += num;
    mx[k % m] += num / 2;
  }
  ll ans = my[0] / 2;
  if(m % 2 == 0) ans += my[m / 2] / 2;
  rep2(i, 1, (m + 1) / 2) {
    if(my[i] >= my[m - i]) {
      ans += my[m - i];
      my[i] -= my[m - i];
      ans += min(my[i] / 2, mx[i]);
    } else {
      ans += my[i];
      my[m - i] -= my[i];
      ans += min(my[m - i] / 2, mx[m - i]);
    }
  }
  cout << ans << endl;
}