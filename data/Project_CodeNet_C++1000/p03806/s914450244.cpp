#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1e9;
const long double EPS = 1e-10;

struct Drug {
  int a, b, c;
};

int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<Drug> d(n);
  rep(i, n) cin >> d[i].a >> d[i].b >> d[i].c;

  vector<vector<int>> dp(n * 10 + 1, vector<int>(n * 10 + 1, INF));
  dp[0][0] = 0;
  rep(i, n) {
    repr(j, n * 10) {
      if (j - d[i].a < 0) continue;
      repr(k, n * 10) {
        if (k - d[i].b < 0) continue;
        dp[j][k] = min(dp[j][k], dp[j - d[i].a][k - d[i].b] + d[i].c);
      }
    }
  }

  int ans = INF, t = min(n * 10 / ma, n * 10 / mb);
  FOR(i, 1, t + 1) {
    ans = min(ans, dp[ma * i][mb * i]);
  }
  cout << (ans == INF ? -1 : ans) << endl;








  
  return 0;
}