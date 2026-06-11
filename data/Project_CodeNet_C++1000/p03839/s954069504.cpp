
#include <algorithm>
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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
ll INF = 1LL << 60;
int main() {
  ll n, k;
  cin >> n >> k;
  vl a(n), s(n), b(n), bs(n);
  rep(i, n) cin >> a[i];
  s[0] = a[0];
  REP(i, 1, n) { s[i] = s[i - 1] + a[i]; }
  rep(i, n) { b[i] = max(0LL, a[i]); }
  bs[0] = b[0];
  REP(i, 1, n) { bs[i] = bs[i - 1] + b[i]; }
  ll ans = 0;
  REP(i, k - 1, n) {
    rep(j, 2) {
      ll tmp = 0;
      if (j == 0) {
        // all black
        tmp = s[i];
        if (i - k >= 0) {
          tmp -= s[i - k];
        }
      }
      if (i - k >= 0) {
        tmp += bs[i - k];
      }
      tmp += bs[n - 1] - bs[i];
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
