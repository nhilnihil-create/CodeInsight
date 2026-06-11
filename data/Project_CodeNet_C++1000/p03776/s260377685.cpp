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

ll mynchoosek(ll n, ll k) {
  ll ans = 1;
  map<ll, ll> pf;
  auto prime_factor = [&](ll n, ll mode) {
    for (ll i = 2; i * i <= n; i++) {
      while (n % i == 0) {
        pf[i] += mode;
        n /= i;
      }
    }
    if (n != 1) pf[n] += mode;
  };

  rep(i, k) {
    prime_factor(n - i, 1);
    prime_factor(i + 1, -1);
  }

  for (auto& kv : pf) {
    rep(i, kv.second) { ans *= kv.first; }
  }

  return ans;
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, a, b;
  cin >> n >> a >> b;

  vll vs(n);
  map<ll, ll> stat;
  rep(i, n) {
    cin >> vs[i];
    stat[vs[i]]++;
  }
  Sort(vs);

  double mean = 0.0;
  map<ll, ll> mstat;
  rep(i, a) {
    mean += vs[n - 1 - i];
    mstat[vs[n - 1 - i]]++;
  }
  mean /= a;

  ll ans = 0;
  if (vs[n - 1] == vs[n - a]) {
    repLRE(i, a, b) {
      ll nn = stat[vs[n - 1]];
      ans += mynchoosek(nn, i);
    }
  } else {
    ll nn = stat[vs[n - a]];
    ll kk = mstat[vs[n - a]];
    ans = mynchoosek(nn, kk);
  }

  cout << mean << endl;
  cout << ans << endl;

  return 0;
}
