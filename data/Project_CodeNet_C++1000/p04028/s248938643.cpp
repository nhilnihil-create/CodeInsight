#include <cmath>
#include <cstdio>
#include <limits>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>
#include <array>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = n-1; i >= 0; --i)
#define REP(i, s, n) for (int i = s; i< (int)(n); ++i)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
ll inf = ll(1e18);
ll mod = ll(1e9) + 7;

void solve(istream &ccin = cin, ostream &ccout = cout) {
  ll n;
  ccin >> n;
  string s;
  ccin >> s;

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
  dp.at(0).at(0) = 1;
  REP(i, 1, n + 1) {
    rep(j, n + 1) {
      if (j == 0) {
        dp.at(i).at(j) = 2 * dp.at(i - 1).at(j + 1) % mod + dp.at(i - 1).at(0);
      } else if (j == n) {
        dp.at(i).at(j) = dp.at(i - 1).at(j - 1) % mod;
      } else {
        dp.at(i).at(j) = (dp.at(i - 1).at(j - 1) + 2 * dp.at(i - 1).at(j + 1)) % mod;
      }
    }
  }
  ccout << dp.at(n).at(s.size()) % mod << endl;

}

int main() {
  ios::sync_with_stdio(false);
  solve();
  return 0;
}