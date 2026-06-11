#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

ll dp[51][51][2501];

int main(){
  ll n;
  ll a;
  cin >> n >> a;
  ll ans=0;
  vector<int> x(n);
  dp[0][0][0]=1;
  rep(i,n) cin >> x[i];
  for (int i=0;i <= n;i++){
    for (int j=0;j <= n;j++){
      for (int s=0;s < 2501;s++){
        if (i >=1 && s < x[i-1]){
          dp[i][j][s]=dp[i-1][j][s];
        }
        else if (i >= 1 && j>=1 && s >= x[i-1]){
          dp[i][j][s]=dp[i-1][j][s]+dp[i-1][j-1][s-x[i-1]];
        }
        else if (i==0 && j == 0 && s==0){
          dp[i][j][s]=1;
        }
        else dp[i][j][s]=0;
      }
    }
  }
  for (int i=1;i <= n;i++){
    ans+=dp[n][i][i*a];
  }
  //rep(i,n+1){
  //  rep(j,n+1){
  //    rep(k,34){
  //      cout << dp[i][j][k] << " ";
  //    }
  //    printf("\n");
  //  }
  //  printf("\n");
  //}
  cout << ans << endl;

  
  return 0;
}