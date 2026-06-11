#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;



int main(){
  
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> dp(n+1,vector<int>(m+1));
  dp[0][0] = 0;
  set<int> st;
  st.insert(0);
  rep(i,n){
    rep(j,m){
      dp[i+1][j] = dp[i][j]+m-j*2;
      st.insert(dp[i+1][j]);
      dp[i][j+1] = dp[i][j]+n-i*2;
      st.insert(dp[i][j+1]);
    }
  }
  if(st.count(k)>0) cout << "Yes" << endl;
  else cout << "No" << endl;
}