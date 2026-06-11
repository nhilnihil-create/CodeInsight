#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  REP(i, n) {
    REP(j, m) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  set<int> used;
  int usedc = 0;
  int ans = n + 1;
  while (usedc < m) {
    int count[m] = {};
    REP(i, n) {
      REP(j, m) {
        if (used.find(a[i][j]) == used.end()) {
          count[a[i][j]]++;
          break;
        }
      }
    }

    int maxi = -1;
    int tmp = 0;
    REP(i, m) {
      if (count[i] > tmp) {
        tmp = count[i];
        maxi = i;
      }
    }
    used.insert(maxi);
    usedc++;
    ans = min(tmp, ans);
  }

  cout << ans << endl;
}
