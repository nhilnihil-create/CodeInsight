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
  ll n;
  string s, t;
  cin >> n >> s >> t;
  ll ans = n * 2;
  rep2(i, 1, n + 1) {
    bool ok = true;
    rep(j, i) if(s[n - i + j] != t[j]) ok = false;
    if(ok) ans = 2 * n - i;
  }
  cout << ans << endl;
}