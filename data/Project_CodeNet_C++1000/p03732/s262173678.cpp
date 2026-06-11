#include<bits/stdc++.h>
using namespace std;
long N,W,w[100],v[100],res;
map<long,long>dp;
int main(){
  cin>>N>>W;
  for(int i=0;i<N;i++)cin>>w[i]>>v[i];
  dp[0]=0;
  for(int i=0;i<N;i++){
    auto tmp=dp;
    for(auto p:tmp){
      auto x=p.first+w[i];
      auto y=p.second+v[i];
      if(x<=W)res=max(res,dp[x]=max(dp[x],y));
    }
  }
  cout<<res<<endl;
}
