#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vl v(n);
  rep(i, n) cin >> v[i];
  vector<vl> c(51, vl(51, 0));
  c[0][0] = 1;
  rep(i, 50) rep(j, 50) {
    if(c[i][j] == 0) continue;
    c[i + 1][j] += c[i][j];
    c[i + 1][j + 1] += c[i][j];
  }
  ll mx = *max_element(all(v));
  map<ll, ll, greater<ll>> mp;
  rep(i, n) mp[v[i]]++;
  double ans = 0;
  ll m = 0;
  for(auto p : mp) {
    ll num = p.first;
    ll cnt = p.second;
    if(a - m > cnt) {
      m += cnt;
      ans += num * cnt;
    } else if(a - m == cnt) {
      ans += num * cnt;
      ans /= double(a);
      printf("%.10f\n1\n", ans);
      return 0;
    } else {
      ans += num * (a - m);
      ans /= double(a);
      ll ans2 = c[cnt][a - m];
      if(num == mx)
        for(ll i = a - m + 1; i <= b - m; i++) ans2 += c[cnt][i];
      printf("%.10f\n", ans);
      cout << ans2 << endl;
      return 0;
    }
  }
}