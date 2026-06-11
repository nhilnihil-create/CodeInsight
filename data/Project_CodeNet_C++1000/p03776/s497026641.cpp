#include <algorithm>
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

int main() {
  //
  ll n, a, b;
  cin >> n >> a >> b;
  vvl comb(51, vl(51, 0));
  comb[0][0] = 1;
  comb[1][0] = 1;
  comb[1][1] = 1;
  REP(i, 2, 51) {
    comb[i][0] = 1;
    comb[i][i] = 1;
    REP(j, 1, i) {
      // cout << i << "," << j << endl;
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }
  map<ll, ll, greater<ll>> mp;
  rep(i, n) {
    ll v;
    cin >> v;
    if (mp.find(v) == mp.end()) {
      mp[v] = 1;
    } else {
      mp[v]++;
    }
  }
  ll total = 0;
  double avg = 0;
  bool first = true;
  ll minnum_cnt = 0;
  ll minnum_select = 0;
  ll s = 0;
  for (auto& x : mp) {
    ll v = x.first;
    ll cnt = x.second;
    if (total + cnt >= a) {
      s += v * (a - total);
      avg = (double)s / a;
      minnum_cnt = cnt;
      minnum_select = a - total;
      break;
    } else {
      total += cnt;
      first = false;
      s += v * cnt;
    }
  }
  cout << setprecision(8) << fixed << avg << endl;
  ll ans = 0;
  if (first) {
    REP(i, a, min(minnum_cnt + 1, b + 1)) {
      ans += comb[minnum_cnt][i];
      // cout << minnum_cnt << ":" << i << ":" << comb[minnum_cnt][i] << endl;
    }
  } else {
    ans += comb[minnum_cnt][minnum_select];
  }
  cout << ans << endl;
  return 0;
}
