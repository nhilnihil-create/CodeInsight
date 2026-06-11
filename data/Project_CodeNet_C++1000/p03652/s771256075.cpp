#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  REP(i, n) REP(j, m) {
    cin >> a[i][j];
    a[i][j]--;
  }
  bool ng[m];
  REP(i, m) ng[i] = false;
  int ans = n;
  REP(k, m) {
    int cnt[m];
    REP(i, m) cnt[i] = 0;
    REP(i, n) {
      bool next = false;
      REP(j, m) {
        if (next) continue;
        if (!ng[a[i][j]]) {
          cnt[a[i][j]]++;
          next = true;
        }
      }
    }
    int mx = 0;
    REP(i, m) {
      if (cnt[mx] < cnt[i]) mx = i;
    }
    ans = min(ans, cnt[mx]);
    ng[mx] = true;
  }
  cout << ans << endl;
  return 0;
}