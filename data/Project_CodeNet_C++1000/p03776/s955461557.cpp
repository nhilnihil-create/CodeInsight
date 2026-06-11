#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

ll getcomb(ll x, ll y) {
  ll ans = 1, n = x - y + 1, r = 1;
  while (n <= x) {
    while (r <= y && ans % r == 0) {
      ans /= r;
      r++;
    }
    ans *= n;
    n++;
  }
  while (r <= y) {
    ans /= r;
    r++;
  }
  return ans;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  sort(v.begin(), v.end(), greater<ll>());
  vector<ll> sum(b - a + 1);
  ll res = 0;
  rep(i, a) res += v[i];
  rep(i, b - a + 1) {
    sum[i] = res;
    res += v[a + i];
  }

  vector<ll> ans;
  ll idx = 0;
  rep(i, b - a + 1) {
    if (sum[i] * (idx + a) > sum[idx] * (i + a)) {
      ans.clear();
      ans.push_back(i + a);
      idx = i;
    }
    else if (sum[i] * (idx + a) == sum[idx] * (i + a)) {
      ans.push_back(i + a);
    }
  }

  long double ave = (long double)sum[idx] / (long double)(idx + a);
  cout << setprecision(20) << ave << endl;

  ll m = ans.size();
  ll comb = 0;
  rep(i, m) {
    ll x = 0, y = 0, id = ans[i] - 1;
    while (id >= 0 && v[id] == v[ans[i] - 1]) {
      x++;
      y++;
      id--;
    }
    id = ans[i];
    while (id < n && v[id] == v[ans[i] - 1]) {
      x++;
      id++;
    }
    comb += getcomb(x, y);
  }
  cout << comb << endl;







  
  return 0;
}