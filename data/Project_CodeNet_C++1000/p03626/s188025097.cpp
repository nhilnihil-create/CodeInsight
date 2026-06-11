#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  int n;
  cin >> n;
  vector<string> s(2);
  rep(i, 2) cin >> s[i];

  vector<bool> c;
  rep(i, n) {
    if (s[0][i] == s[1][i]) c.push_back(false);
    else {
      c.push_back(true);
      i++;
    }
  }

  int m = c.size();
  bool res = c[0];
  ll ans = 3;
  if (c[0]) ans *= 2;
  FOR(i, 1, m) {
    if (res) {
      if (c[i]) ans = (ans * 3) % mod;
    }
    else ans = (ans * 2) % mod;
    res = c[i];
  }
  cout << ans << endl;






  
  return 0;
}