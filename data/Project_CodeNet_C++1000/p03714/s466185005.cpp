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

  ll frs = 0;
  multiset<ll> bkq;
  multiset<ll> frms;
  vll as(3*n);
  rep(i, 3*n) {
    ll a;
    cin >> a;
    as[i] = a;
    if (i < n) {
      frs += a;
      frms.insert(a);
    } else {
      bkq.insert(a);
    }
  }
  multiset<ll> bkms;
  ll bks = 0;
  rep(i, n) {
    ll a = *bkq.begin();
    bks += a;
    bkms.insert(a);
    bkq.erase(bkq.begin());
  }

  ll ans = frs - bks;
  ll tmp = ans;
  repLRE(i, n, 2 * n - 1) {
    ll a = as[i];
    // fr
    auto itrf = frms.upper_bound(a);
    if(itrf != frms.begin()){
      auto ifb = frms.begin();
      tmp += a - *ifb;
      frms.insert(a);
      frms.erase(ifb);
    }
    // bk
    auto itrb = bkms.lower_bound(a);
    if(itrb != bkms.end()){
      bkms.erase(a);
      ll inst = *bkq.begin();
      bkq.erase(bkq.begin());
      bkms.insert(inst);
      tmp -= inst - a;
    } else {
      bkq.erase(bkq.lower_bound(a));
    }
    chmax(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
