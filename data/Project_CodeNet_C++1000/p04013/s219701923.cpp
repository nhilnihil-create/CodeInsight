#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
ll dp[55][55][5050];

int main() {
  int n, a;
  cin >> n >> a;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  dp[0][0][0] = 1;
  rep(i, n)rep(j, n)rep(k, 2500) if(dp[i][j][k]){
    dp[i + 1][j][k] += dp[i][j][k];
    dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans += dp[n][i][i * a];
  }
  cout << ans << endl;
}