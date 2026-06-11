#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

static const long long mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;
  vll ts(n), as(n);
  rep(i, n) cin >> ts[i];
  rep(i, n) cin >> as[i];

  ll tmid = -1, tmax = 0;
  rep(i, n) {
    if (tmax < ts[i]) {
      tmid = i;
      tmax = ts[i];
    }
  }
  ll amid = -1, amax = 0;
  rep(i, n) {
    if (amax < as[n - 1 - i]) {
      amid = n - 1 - i;
      amax = as[n - 1 - i];
    }
  }

  if (tmid > amid || tmax != amax) {
    cout << 0 << endl;
    return 0;
  }
  ll maxv = tmax;

  ll ans = 1;
  tmax = 0;
  rep(i, tmid) {
    if (tmax == ts[i]) {
      ans = ans * tmax % mod;
    } else {
      tmax = ts[i];
    }
  }
  repLRE(i, tmid + 1, amid - 1) { ans = ans * maxv % mod; }
  amax = 0;
  rrepLRE(i, n - 1, amid + 1) {
    if (amax == as[i]) {
      ans = ans * amax % mod;
    } else {
      amax = as[i];
    }
  }

  cout << ans << endl;

  return 0;
}
