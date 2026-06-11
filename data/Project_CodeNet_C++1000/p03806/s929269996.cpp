#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main(){ 
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  vector<vector<int>> dp(401, vector<int>(401,INF));

  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {

    for (int j = 400; j >= 0; j--) {
      for (int k = 400; k >= 0; k--) {
        if (dp[j][k] == INF) continue;
        if (j + a[i] <= 400 && k + b[i] <= 400) {
          dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
        }
      }
    }

  }
  int res = INF;
  for (int i = 1; i <= 400; i++) {
    for (int j = 1; j <= 400; j++) {
      if (i * mb == j * ma) res = min(res, dp[i][j]);
    }
  }
  if (res == INF) cout << -1 << endl;
  else cout << res << endl;
  return 0;  
} 