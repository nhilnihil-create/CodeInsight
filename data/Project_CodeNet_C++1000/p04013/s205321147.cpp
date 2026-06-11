#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a;
  cin >> n >> a;
  vector<int>x(n);
  int i,j;
  for(i=0;i<n;i++){
    cin >> x[i];
    x[i]-=a;
  }
  vector<vector<long> >dp(n,vector<long>(100050,0));
  dp[0][50000+x[0]]=1;
  for(i=1;i<n;i++){
    for(j=100;j<100000;j++){
      dp[i][j+x[i]] = dp[i-1][j]+dp[i-1][j+x[i]];
    }
    dp[i][50000+x[i]]+=1;
  }
  cout<<dp[n-1][50000]<<endl;


}
