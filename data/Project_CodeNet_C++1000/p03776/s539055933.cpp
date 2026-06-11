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
  cin >> n >> a >> b;
  map<ll, ll, greater<ll>> mp;
  rep(i, n) {
    ll v;
    cin >> v;
    mp[v]++;
  }
  vector<vl> c(52, vl(52, 0));
  rep(i, 52) c[i][0] = 1;
  rep2(i, 1, 52) rep2(j, 1, i + 1) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  double sum = 0;
  ll cnt = a;
  for(auto v : mp) {
    ll k = v.first;
    ll m = v.second;
    if(cnt > m) {
      cnt -= m;
      sum += k * m;
    } else if(cnt == m) {
      sum += k * cnt;
      printf("%.6f\n", sum / double(a));
      cout << 1 << endl;
      return 0;
    } else if(sum == 0) {
      printf("%.6f\n", double(k));
      ll ans = 0;
      rep2(i, a, min(b + 1, m + 1)) ans += c[m][i];
      cout << ans << endl;
      return 0;
    } else {
      sum += k * cnt;
      printf("%.6f\n", sum / double(a));
      cout << c[m][cnt] << endl;
      return 0;
    }
  }
}