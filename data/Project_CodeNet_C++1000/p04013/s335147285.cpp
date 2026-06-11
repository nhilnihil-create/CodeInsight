#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
  long long dp[55][3000][55];
  int n,a;
  cin>>n>>a;
  vector<int> x(n);
  for(int i=0;i<n;i++) cin>>x[i];
  
  memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  for(int i=0;i<n;i++){
    for(int s=0;s<=n*a;s++){
       for(int k=0;k<=n;k++){
         if(dp[i][s][k]==0) continue;
         dp[i+1][s][k]+=dp[i][s][k];
         dp[i+1][s+x[i]][k+1]+=dp[i][s][k];
       }
    }
  }
  long long res=0;
  for(int k=1;k<=n;k++) res+=dp[n][a*k][k];
  cout<<res<<endl;
  return 0;
}
