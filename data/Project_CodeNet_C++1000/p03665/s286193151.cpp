#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

int N, P;
vector<int> A;
int dp[51][2];

int dfs(int n, int m) {
  if ( n == N ) {
    if ( m == P ) return 1;
    else return 0;
  }

  if ( dp[n][m] >= 0 ) return dp[n][m];
  int ret = dfs(n+1, (m+A[n])%2) + dfs(n+1, m);
  return dp[n][m] = ret;  
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> P;
  A.resize(N);
  REP(i, N) cin >> A[i];

  fill_n(*dp, 51*2, -1);
  cout << dfs(0, 0) << endl;

  return 0;
}
