#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;
int64_t INF = 10000000000;
int main(){
  int64_t n,ma,mb;
  cin >> n >> ma >> mb;
  vector<int64_t> a(n),b(n),c(n);
  rep(i,n){
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<vector<int64_t>>> dp(n+1,vector<vector<int64_t>>(105,vector<int64_t>(105,INF)));
  dp[0][0][0] = 0;
  rep(i,n){
    rep(aw,100+1){
      rep(bw,100+1){
        dp[i+1][aw][bw] = dp[i][aw][bw];
        if(aw-a[i] >= 0 && bw-b[i] >= 0){
          dp[i+1][aw][bw] = min(dp[i+1][aw][bw],dp[i][aw-a[i]][bw-b[i]]+c[i]);
        }
      }
    }
  }
  int64_t minprice = INF;
  rep(i,100){
    if(i != 0 && ma*i <= 100 && mb*i <= 100 && dp[n][ma*i][mb*i] < INF){
      minprice = min(minprice,dp[n][ma*i][mb*i]);
    }
  }
  cout << (minprice < INF?minprice:-1) << endl;
      
    
}
                                