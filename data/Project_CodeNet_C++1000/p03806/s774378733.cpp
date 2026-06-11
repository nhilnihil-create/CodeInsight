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
#define rSort(v) sort(v.rbegin(), v.rend())
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
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, ma, mb;
  cin >> n >> ma >> mb;
  vll as(n), bs(n), cs(n);

  rep(i, n) cin >> as[i] >> bs[i] >> cs[i];

  ll n1 = n / 2;
  ll n2 = n - n1;

  vll lol, clol;
  rep(s, 1 << n1){
    if (s == 0) continue;
    ll sig = 0, tau = 0, csum = 0;
    rep(j, n1) { if (s >> j & 1) {
        sig += as[j], tau += bs[j], csum += cs[j];
      }
    }
    lol.push_back(mb*sig - ma*tau);
    clol.push_back(csum);
  }

  map<ll, ll> mp;
  rep(s, 1 << n2) {
    if (s == 0) continue;
    ll sig = 0, tau = 0, csum = 0;
    rep(j, n2) { if (s >> j & 1) {
        sig += as[n1 + j], tau += bs[n1 + j], csum += cs[n1 + j];
      }
    }
    ll etry = mb * sig - ma * tau;
    if (mp.count(etry) == 0) {
      mp[etry] = csum;
    } else {
      chmin(mp[etry], csum);
    }
  }

  ll ans = INF;
  ll ncan = lol.size();
  rep(i,ncan){
    if(lol[i] == 0) chmin(ans, clol[i]);
    if(mp.count(-lol[i]) != 0) {
      chmin(ans, clol[i] + mp[-lol[i]]);
    }
  }
  if (mp.count(0) != 0) chmin(ans, mp[0]);

  if (ans == INF) ans = -1;

  cout << ans << endl;

  return 0;
}
