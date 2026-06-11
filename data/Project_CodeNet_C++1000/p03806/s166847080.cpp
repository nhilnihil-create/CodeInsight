#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> a(N), b(N), c(N);
  int sum_a = 0, sum_b = 0;
  rep(i,N) {
    cin >> a[i] >> b[i] >> c[i];
    sum_a += a[i];
    sum_b += b[i];
  }
  int dp[N][sum_a + 1][sum_b + 1];
  rep(k,N) rep(i,sum_a+1) rep(j,sum_b+1) dp[k][i][j] = INF;
  dp[0][0][0] = 0;
  dp[0][a[0]][b[0]] = c[0];
  for (int k = 1; k < N; k++) rep(i,sum_a+1) rep(j,sum_b+1) {
    dp[k][i][j] = dp[k - 1][i][j];
    if (i - a[k] >= 0 && j - b[k] >= 0) {
      dp[k][i][j] = min(dp[k][i][j], dp[k - 1][i - a[k]][j - b[k]] + c[k]);
    }
  }
  
  int ans = INF;
  for (int k = 1; Ma * k <= sum_a && Mb * k <= sum_b; k++) {
    ans = min(ans, dp[N - 1][Ma * k][Mb * k]);
  }

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  
  return 0;
}