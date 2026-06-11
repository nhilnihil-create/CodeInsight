#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<vector<int> > a(n, vector<int>(n)); REP(i, n) REP(j, n) cin >> a[i][j];
  long long ans = 0;
  REP(i, n) FOR(j, i+1, n) {
    bool same = false;
    REP(k, n) if (k != i && k != j) {
      if (a[i][j] == a[i][k] + a[k][j]) same = true;
      else if (a[i][j] > a[i][k] + a[k][j]) {
        cout << -1 << '\n';
        return 0;
      }
    }
    if (!same) ans += a[i][j];
  }
  cout << ans << '\n';
  return 0;
}
