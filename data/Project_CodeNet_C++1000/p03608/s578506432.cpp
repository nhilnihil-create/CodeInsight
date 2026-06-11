#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 1e8;

int main(){ 
  int n, m, R;
  cin >> n >> m >> R;
  vector<int> r(R);
  rep(i,R) cin >> r[i], r[i]--;
  sort(r.begin(), r.end());
  vector<vector<int>> dp(n, vector<int>(n, INF));
  rep(i,n) dp[i][i] = 0;
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dp[a][b] = c;
    dp[b][a] = c;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int res = INF;

  do {
    int tmp = 0; 
    for (int i = 0; i < R - 1; i++) tmp += dp[r[i]][r[i + 1]];
    res = min(res, tmp);
  } while (next_permutation(r.begin(), r.end()));

  cout << res << endl;
  return 0; 
} 
