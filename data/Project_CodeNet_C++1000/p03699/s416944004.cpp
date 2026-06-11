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
  vl s(n);
  rep(i, n) cin >> s[i];
  ll sum = accumulate(all(s), 0LL);
  sort(all(s));
  rep(i, n) {
    if(sum % 10 > 0) break;
    if(s[i] % 10 > 0) sum -= s[i];
  }
  cout << (sum % 10 > 0 ? sum : 0) << endl;
}