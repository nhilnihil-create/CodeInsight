#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;



int main(){
  
  int n,m,k;
  cin >> n >> m >> k;
  if(k == 0){
    cout << "Yes" << endl;
    return 0;
  }
  vector<vector<int>> dp(n+2,vector<int>(m+2));
  rep(i,n+1){
    rep(j,m+1){
      if(dp[i][j] == k){
        cout << "Yes" << endl;
        return 0;
      }
      dp[i+1][j] = dp[i][j]+m-j*2;
      dp[i][j+1] = dp[i][j]+n-i*2;
    }
  }
  cout << "No" << endl;
}