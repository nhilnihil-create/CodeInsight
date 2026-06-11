#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int INF = 1e9;

const int nmax = 40, abmax = 10;
ll dp[nmax + 1][nmax * abmax + 1][nmax * abmax + 1];

int main(int argc, const char * argv[]) {
  int N, MA, MB;
  cin >> N >> MA >> MB;
  vector<int> alist(N), blist(N), clist(N);
  for (int i = 0; i < N; i++) {
    cin >> alist[i] >> blist[i] >> clist[i];
  }

  for (int i = 0; i <= nmax; i++) {
    for (int j = 0; j <= nmax * abmax; j++) {
      for (int k = 0; k <= nmax * abmax; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= nmax * abmax; j++) {
      for (int k = 0; k <= nmax * abmax; k++) {
        if (dp[i][j][k] == INF) continue;
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        dp[i + 1][j + alist[i]][k + blist[i]] = min(dp[i + 1][j + alist[i]][k + blist[i]], dp[i][j][k] + clist[i]);
      }
    }
  }

  ll ans = INF;
  for (int i = 1; i <= N; i++) {
    int a = MA * i, b = MB * i;
    if (a > nmax * abmax || b > nmax * abmax) {
      continue;
    }
    ans = min(ans, dp[N][a][b]);
  }

  if (ans == INF) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}