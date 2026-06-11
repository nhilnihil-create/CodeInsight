#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A;
  cin>>N>>A;
  vector<int> x(N);
  for(int i=0;i<N;++i) cin>>x[i];


  //x[0],..,x[i-1]までからj個選んで和をsにする総通りdp[i][j][s];
  //i=0は空
  int64_t dp[N+1][N+1][3000];
  
  dp[0][0][0]=1;
  for(int j=0;j<=N;++j){
  for(int s=1;s<3000;++s){
    dp[0][j][s]=0;
  }
  }

  for(int i=1;i<=N;++i){
    for(int j=0;j<=N;++j){
      for(int s=0;s<3000;++s){
        //j=0つまり選ばない時
        if(j==0){
          if(s==0) dp[i][j][s]=1;
          else dp[i][j][s]=0;
        }
        //選ぶとき
        else{
          if(x[i-1]>s) dp[i][j][s]=dp[i-1][j][s];
          else dp[i][j][s]=dp[i-1][j][s]+dp[i-1][j-1][s-x[i-1]];
        }
      }
    }
  }

  int64_t sum=0;
  for(int i=1;i<=N;++i){
    sum += dp[N][i][i*A];
  }

  cout<<sum<<endl;

}