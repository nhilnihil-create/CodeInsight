#include <algorithm>
#include <bitset>
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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<long long> x(n); REP(i, n) cin >> x[i];
  vector<long long> diff(n - 1);
  REP(i, n - 1) diff[i] = x[i + 1] - x[i];
  int m; long long k; cin >> m >> k;
  vector<vector<int> > pos(61, vector<int>(n - 1));
  REP(i, n - 1) pos[0][i] = i;
  while (m--) {
    int a; cin >> a; --a;
    swap(pos[0][a - 1], pos[0][a]);
  }
  REP(i, 60) REP(j, n - 1) pos[i + 1][j] = pos[i][pos[i][j]];
  vector<int> rabbit(n - 1);
  REP(i, n - 1) rabbit[i] = i;
  REP(i, n - 1) {
    REP(j, 61) if (k >> j & 1) rabbit[i] = pos[j][rabbit[i]];
  }
  vector<double> ans(n);
  ans[0] = x[0];
  REP(i, n - 1) ans[i + 1] = ans[i] + diff[rabbit[i]];
  REP(i, n) printf("%.11f\n", ans[i]);
  return 0;
}
