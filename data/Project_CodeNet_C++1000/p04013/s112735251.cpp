#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
int N, A;
cin >> N >> A;
vector<int> X(N);
rep(i,N) cin >> X[i];

vector<vector<vector<ll>>> dp(51,vector<vector<ll>>(51,vector<ll> (2501,0)));



rep(j,N+1){
  rep(k,N+1){
    rep(s,N*50+1){
      if(j==0 && k == 0 && s == 0)dp[j][k][s] = 1;
      else if(j > 0 && s < X[j-1]) dp[j][k][s] = dp[j-1][k][s];
      else if(j > 0 && k > 0 && s >= X[j-1]) dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-X[j-1]];
      else dp[j][k][s] = 0;
      //cout << dp[j][k][s] << " ";
    }
    //cout << endl;
  }
  //cout << endl;
}

ll ans = 0;
rep(k,N+1) ans += dp[N][k][k*A];

cout << ans-1 << endl;

}
