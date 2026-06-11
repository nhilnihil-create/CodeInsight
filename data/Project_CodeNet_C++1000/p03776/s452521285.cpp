#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
 int n,a,b;
 cin>>n>>a>>b;
 pair<int,int> dp[n][n+1];
 int v[n];
for(int i=0;i<n;i++)cin>>v[i];
dp[0][0]=make_pair(0,1);
dp[0][1]=make_pair(v[0],1);
for(int i=1;i<n;i++){
  dp[i][0]=make_pair(0,1);
  for(int j=1;j<=i;j++){
    if(dp[i-1][j-1].first+v[i]>dp[i-1][j].first)dp[i][j]=make_pair(dp[i-1][j-1].first+v[i],dp[i-1][j-1].second);
    else{
      if(dp[i-1][j-1].first+v[i]<dp[i-1][j].first)dp[i][j]=dp[i-1][j];
      else dp[i][j]=make_pair(dp[i-1][j-1].first+v[i],dp[i-1][j-1].second+dp[i-1][j].second);
    }
  }
  dp[i][i+1]=make_pair(dp[i-1][i].first+v[i],1);
}
int ans2=a;
pair<int,int> ans1=dp[n-1][a];
for(int i=a+1;i<=b;i++){
  if(i*ans1.first<ans2*dp[n-1][i].first){
    ans1=dp[n-1][i];
    ans2=i;
  }else{
    if(i*ans1.first==ans2*dp[n-1][i].first)ans1.second+=dp[n-1][i].second;
  }
}
//cerr<<ans1.first<<' '<<ans2<<' '<<ans1.second<<endl;
cout<< std::setprecision(23) <<double(ans1.first)/double(ans2)<<endl<<ans1.second;
return 0;
}
