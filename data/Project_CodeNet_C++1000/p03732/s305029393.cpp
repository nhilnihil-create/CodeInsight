#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
ll dp[101][101][500];
int main() {
  int n, W;
  cin >> n >> W;
  vector<ll> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  int d = w[0];
  rep(i, n) {
    w[i] -= d;
  }
  rep(i,n)rep(j,n)rep(k,500) {
    ll ni = i + 1;
    ll nj = j + 1;
    ll nk = k + w[i];
    
    dp[ni][j][k] = max(dp[ni][j][k], dp[i][j][k]);
    if(nk + (nj * d) > W) continue;
    if(dp[ni][nj][nk] < dp[i][j][k] + v[i]) {
      dp[ni][nj][nk] = dp[i][j][k] + v[i];
    }
  }
  ll ans = 0;
  rep(i, n + 1) rep(j, 500){
    ans = max(ans, dp[n][i][j]);
  }
  cout << ans << endl;

}