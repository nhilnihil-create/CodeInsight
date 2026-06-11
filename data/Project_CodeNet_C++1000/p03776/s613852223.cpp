#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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
  vector<vl> c(51, vl(51, 0));
  c[0][0] = 1;
  rep2(i, 1, 51) rep(j, i + 1) {
    if(j == 0)
      c[i][j] = 1;
    else
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  ll x = a;
  double ave = 0;
  for(auto v : mp) {
    ll k = v.first;
    ll m = v.second;
    if(m < x) {
      ave += k * m;
      x -= m;
    } else if(x == a) {
      printf("%.6f\n", double(k));
      ll ans = 0;
      rep2(i, a, b + 1) ans += c[m][i];
      cout << ans << endl;
      return 0;
    } else {
      ave += k * x;
      ave /= double(a);
      printf("%.6f\n", ave);
      cout << c[m][x] << endl;
      return 0;
    }
  }
}