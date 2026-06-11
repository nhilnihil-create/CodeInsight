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
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  ll ans = 0;
  rep(i, n - 1) {
    ans += min(b, a * (x[i + 1] - x[i]));
  }
  cout << ans << endl;


  
  return 0;
}