#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;
int main() {
  //
  ll n, k;
  cin >> n >> k;
  vl a(n);
  rep(i, n) cin >> a[i];
  if (n == 1) {
    if (a[0] >= k) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }

  vector<bitset<5001>> dp1(n), dp2(n);
  vvl dp3(n, vl(5001, 0));
  dp1[0][0] = 0;
  if (a[0] < k) {
    dp1[0][a[0]] = 1;
  }
  REP(i, 1, n) {
    if (a[i] < k) {
      dp1[i][a[i]] = 1;
    }
    rep(v, k) {
      dp1[i][v] = max(dp1[i][v], dp1[i - 1][v]);
      if (v - a[i] >= 0) {
        dp1[i][v] = max(dp1[i][v], dp1[i - 1][v - a[i]]);
      }
    }
  }
  dp2[n - 1][0] = 0;
  dp3[n - 1][0] = 0;
  if (a[n - 1] < k) {
    dp2[n - 1][a[n - 1]] = 1;
    REP(v, 1, k) { dp3[n - 1][v] = dp3[n - 1][v - 1] + dp2[n - 1][v]; }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < k) {
      dp2[i][a[i]] = 1;
    }
    rep(v, k) {
      dp2[i][v] = max(dp2[i][v], dp2[i + 1][v]);
      if (v - a[i] >= 0) {
        dp2[i][v] = max(dp2[i][v], dp2[i + 1][v - a[i]]);
      }
    }
    dp3[i][0] = dp2[i][0];
    REP(v, 1, k) { dp3[i][v] = dp3[i][v - 1] + dp2[i][v]; }
  }
  // rep(i, n) {
  //   rep(v, k) { cerr << dp1[i][v] << " "; }
  //   cerr << endl;
  // }
  // cerr << endl;
  // rep(i, n) {
  //   rep(v, k) { cerr << dp2[i][v] << " "; }
  //   cerr << endl;
  // }
  // cerr << endl;
  // rep(i, n) {
  //   rep(v, k) { cerr << dp3[i][v] << " "; }
  //   cerr << endl;
  // }

  ll ans = 0;
  ll tmp = dp3[1][k - 1];
  if (k - a[0] - 1 >= 0) {
    tmp -= dp3[1][k - a[0] - 1];
  }
  if (a[0] < k && tmp == 0) ans++;
  // cerr << ans << endl;
  if (a[n - 1] <= k - 1) {
    ll cnt = 0;
    // cerr << dp1[n - 2][k - a[n - 1]] << endl;
    REP(v, max(0LL, k - a[n - 1]), k) {
      if (dp1[n - 2][v]) {
        cnt++;
        break;
      }
    }
    if (a[n - 1] < k && cnt == 0) {
      ans++;
    }
  }
  // cerr << ans << endl;
  REP(i, 1, n - 1) {
    if (a[i] >= k) continue;
    ll cnt = 0;
    rep(v, k) {
      if (dp1[i - 1][v] || v == 0) {
        ll tmp = dp3[i + 1][k - 1 - v];
        if (k - v - a[i] - 1 >= 0) {
          tmp -= dp3[i + 1][k - a[i] - v - 1];
        } else if (v > 0 && k - a[i] >= v) {
          cnt++;
          continue;
        }
        if (tmp > 0) {
          cnt++;
        }
      }
    }
    if (cnt == 0) {
      // cerr << dp1[i - 1][799] << endl;
      // cerr << "+" << i << "," << a[i] << endl;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
