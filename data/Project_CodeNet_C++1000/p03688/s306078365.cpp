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
  ll n;
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    mp[a]++;
  }
  bool ng = false;
  if(mp.size() > 2) ng = true;
  ll k = (*mp.begin()).first;
  if((*mp.rbegin()).first - k > 1) ng = true;
  if(mp.size() == 1) {
    if(k != n - 1 && n / k < 2) ng = true;
  } else {
    ll x = (*mp.begin()).second;
    if(n - k < k - x + 2) ng = true;
    if(x > k) ng = true;
  }
  cout << (ng ? "No" : "Yes") << endl;
}