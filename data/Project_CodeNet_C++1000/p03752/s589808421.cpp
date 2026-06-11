#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

const ll INF = 1LL << 50;

const ll mod = 1e9 + 7;

int main() {
  ll n, k;
  cin >> n >> k;

  vll as(n);
  rep(i, n) cin >> as[i];

  ll ans = LONG_LONG_MAX;
  rep(s, 1LL << n) {
    ll pcnt = __builtin_popcount(s);
    if (pcnt != k) continue;
    ll ctot = 0;  // cost total
    ll cht = 0;   // current hight
    rep(i, n) {
      bool cond = (s >> i & 1);
      if (cond) {
        if (as[i] <= cht) {
          ctot += cht - as[i] + 1;
          cht++;
          continue;
        }
      }
      chmax(cht, as[i]);
    }  // i
    chmin(ans, ctot);
  }  // s

  cout << ans << endl;

  return 0;
}
