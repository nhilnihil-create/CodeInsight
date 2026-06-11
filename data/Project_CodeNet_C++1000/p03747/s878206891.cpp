#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
// http://drken1215.hatenablog.com/entry/2018/07/27/124500
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, l, t; cin >> n >> l >> t;
  vector<int> x(n), w(n); REP(i, n) cin >> x[i] >> w[i];
  vector<int> coordinates(n);
  REP(i, n) {
    if (w[i] == 1) coordinates[i] = (x[i] + t) % l;
    else coordinates[i] = ((x[i] - t) % l + l) % l;
  }
  sort(ALL(coordinates));
  long long cnt = 0;
  REP(i, n) {
    if (w[i] == 1) {
      if (l - x[i] > t) continue;
      int rem = t - (l - x[i]);
      --cnt;
      cnt -= rem / l;
    } else {
      if (x[i] + 1 > t) continue;
      int rem = t - (x[i] + 1);
      ++cnt;
      cnt += rem / l;
    }
    // cout << i << ' ' << cnt << '\n';
    cnt %= n;
  }
  (cnt += n) %= n;
  vector<int> ans(n);
  int idx = 0;
  FOR(i, cnt, n) {
    ans[i] = coordinates[idx];
    ++idx;
  }
  REP(i, cnt) {
    ans[i] = coordinates[idx];
    ++idx;
  }
  REP(i, n) cout << ans[i] << '\n';
  return 0;
}
