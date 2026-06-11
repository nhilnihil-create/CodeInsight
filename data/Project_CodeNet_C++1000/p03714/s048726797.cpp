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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;

  vll as(3 * n);
  rep(i, 3 * n) cin >> as[i];

  vll lef(n+1);
  ll sum = 0;
  priority_queue<ll, vll, greater<ll>> pql;
  rep(i, n) {
    sum += as[i];
    pql.emplace(as[i]);
  }
  lef[0] = sum;
  repLRE(i, n, 2 * n - 1) {
    ll t = pql.top();
    if (t < as[i]) {
      pql.push(as[i]);
      pql.pop();
      sum += as[i] - t;
    }
    lef[i - n + 1] = sum;
  }

  vll rig(n+1);
  sum = 0;
  priority_queue<ll> pqr;
  rep(i, n) {
    sum += as[3*n - 1 - i];
    pqr.emplace(as[3*n - 1 - i]);
  }
  rig[n] = sum;
  rrepLRE(i, 2 * n - 1, n) {
    ll t = pqr.top();
    if (t > as[i]) {
      pqr.push(as[i]);
      pqr.pop();
      sum += as[i] - t;
    }
    rig[i - n] = sum;
  }
  ll ans = LONG_LONG_MIN;
  rep(i, n+1) chmax(ans, lef[i] - rig[i]);

  cout << ans << endl;
  return 0;
}