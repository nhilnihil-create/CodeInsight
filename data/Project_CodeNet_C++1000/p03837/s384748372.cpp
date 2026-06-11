#include<bits/stdc++.h>
using namespace std;
static const int64_t INF=10000000000000;
struct edge{int64_t from,to,cost;};
int main(){
  int64_t N,M;cin>>N>>M;
  vector<edge>es(M);
  for(int i=0;i<M;i++){
  int64_t a,b,c;cin>>a>>b>>c;
    a--;b--;
    es[i].from=a;
    es[i].to=b;
    es[i].cost=c;
  }vector<vector<int64_t>>dp(N,vector<int64_t>(N,INF));
  for(int64_t i=0;i<N;i++)
    dp[i][i]=0;
  for(int i=0;i<M;i++){
  int64_t a=es[i].from;
    int64_t b=es[i].to;
    int64_t c=es[i].cost;
    dp[a][b]=c;
    dp[b][a]=c;
  }for(int64_t k=0;k<N;k++)
    for(int64_t i=0;i<N;i++)
      for(int64_t j=0;j<N;j++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
  int64_t ans=0;
  for(int i=0;i<M;i++){
  int64_t a=es[i].from;
    int64_t b=es[i].to;
    int64_t c=es[i].cost;
    bool x=false;
    for(int j=0;j<N;j++){
    if(x)break;
      if(dp[j][a]+c==dp[j][b] || dp[j][b]+c==dp[j][a])
        x=true;
    }if(x)ans++;
  
  }ans=M-ans;
cout<<ans<<endl;
   return 0;
}