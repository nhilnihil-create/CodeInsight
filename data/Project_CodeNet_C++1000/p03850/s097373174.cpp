#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF (1LL<<60)
#define MOD 1000000007

int N;
int A[100000];
bool sign[100000];

long long dp[100001][3];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) {
    if (i > 0) {
      char c;
      cin >> c;
      sign[i] = c == '-';
    }
    cin >> A[i];
  }

  rep(i, N) {
    rep(j, 3) dp[i][j] = -INF;
  }
  dp[0][0] = 0;
  rep(i, N) {
    rep(d, 3) {
      if (dp[i][d] == -INF) continue;
      int nd = d;
      if (sign[i]) {
        nd++;
        if (nd == 3) nd = 1;
      }
      int b = (nd % 2 == 0) ? 1 : -1;
      dp[i+1][nd] = max(dp[i+1][nd], dp[i][d] + 1LL*b*A[i]);
    }

    dp[i+1][1] = max(dp[i+1][1], dp[i+1][2]);
    dp[i+1][0] = max(dp[i+1][0], dp[i+1][1]);
  }
  cout << dp[N][0] << "\n";
  return 0;
}
