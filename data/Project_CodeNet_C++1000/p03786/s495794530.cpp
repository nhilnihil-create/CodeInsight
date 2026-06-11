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
  vl a(n), cum(n + 1, 0);
  rep(i, n) cin >> a[i];
  sort(all(a));
  rep(i, n) cum[i + 1] = cum[i] + a[i];
  vl dp(n, 1);
  rep(i, n - 1) if(cum[i + 1] * 2 >= a[i + 1]) dp[i + 1] += dp[i];
  cout << dp[n - 1] << endl;
}