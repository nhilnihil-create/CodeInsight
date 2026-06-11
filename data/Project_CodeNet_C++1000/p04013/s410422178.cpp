#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2e5+100;
ll dp[55][55][55*55];///总共有i张牌选了j张的总和为k的个数
ll x[55];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,a;
    cin>>n>>a;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
        for(int k=0;k<=n*a;k++){
            if(i==0&&j==0&&k==0) dp[i][j][k]=1;
            else if(i>=1&&k<x[i]) dp[i][j][k]=dp[i-1][j][k];
             else if(i>=1&&j>=1&&k>=x[i]) dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i]];
             else dp[i][j][k]=0;
        }
      }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[n][i][i*a];
    }
    cout<<ans<<endl;
    return 0;
}
