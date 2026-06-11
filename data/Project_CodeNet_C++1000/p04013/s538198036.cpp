#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;

ll dp[52][52][2501];

int main(){
  int n,a;
  cin >> n >> a;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];

  //rep(i,n+1) rep(j,n+1) rep(k,2501) dp[i][j][k] == INF;
  dp[0][0][0] = 1;

  rep(i,n) {
    rep(j,n) {
      rep(k,2501){
          dp[i+1][j+1][k + v[i]] += dp[i][j][k];
          dp[i+1][j][k] += dp[i][j][k];
        } 
      }
    //rep(x,n) {
    //  rep(y,10){
    //    cout << dp[i][x][y];
    //  }
    //  cout << endl;
    //}
    //cout << endl;
  }
  ll ans = 0;
  rep(j,n+1) rep(k,2501){
    if (j*a == k ) ans += dp[n][j][k]; 
  }
  cout << ans-1LL << endl;


 
  
  return 0;
  
}
