#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  int n,p;
  cin >> n >> p;
  vector<vector<ll>> dp(n+1,vector<ll>(2));
  dp[0][0] = 1;
  dp[0][1] = 0;
  rep1(i,n){
    int x;
    cin >> x;
    if(x%2 == 0){
      dp[i][0] = dp[i-1][0]*2;
      dp[i][1] = dp[i-1][1]*2;
    }
    if(x%2 == 1){
      dp[i][0] = dp[i-1][0]+dp[i-1][1];
      dp[i][1] = dp[i-1][0]+dp[i-1][1];
    }
  }
  cout << dp[n][p] << endl;
}