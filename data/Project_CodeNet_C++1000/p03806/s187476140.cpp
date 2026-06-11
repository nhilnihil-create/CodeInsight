#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 100000

int main(){
  int N,Ma,Mb;
  cin>>N>>Ma>>Mb;
  vector<int> a(N),b(N),c(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i)>>b.at(i)>>c.at(i);
  }

  vector<vector<int>> dp(500,vector<int>(500,INF));
  dp.at(0).at(0)=0;
  for(int i=0;i<N;i++){
    for(int j=400-a.at(i);j>=0;j--){
      for(int k=400-b.at(i);k>=0;k--){
        dp[j+a.at(i)][k+b.at(i)]=min(dp[j+a.at(i)][k+b.at(i)],dp[j][k]+c.at(i));
      }
    }
  }
  int ans=10000000;
  for(int i=1;i*Ma<=400&&i*Mb<=400;i++){
    ans=min(ans,dp[i*Ma][i*Mb]);
  }
  if(ans==INF){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
}
