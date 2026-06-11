#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<bool>dp(N,false);
  vector<int>A(N,1);
  dp[0]=true;
  int M;
  cin>>M;
  for(int i=0;i<M;i++){
  int x,y;
    cin>>x>>y; x--; y--;
    if(dp[x])dp[y]=true;
    A[x]--;A[y]++;if(A[x]==0)dp[x]=false;
  }int ans=0;
  for(int i=0;i<N;i++)
    if(dp[i])ans++;
  cout<<ans<<endl;
  return 0;
}