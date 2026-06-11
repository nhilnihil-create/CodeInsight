#include <bits/stdc++.h>
using namespace std;
long long  a[100005];
char s[100005];
int n;
long long dp[100005][3];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>a[0];
    for(int i =1;i<n;i++)
        cin>>s[i]>>a[i];
    for(int i =0;i<n;i++)
        for(int j =0;j<3;j++)
          dp[i][j]=-1e15;
    dp[0][0]=a[0];
    for(int i =1;i<n;i++)
    {
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-1][2];
        dp[i][0]=dp[i-1][0];
      //  cout<<a[i]<<" "<<s[i]<<endl;
     //   cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        if(s[i]=='-')
        {
             dp[i][0]-=a[i];
             dp[i][1]+=a[i];
             dp[i][2]-=a[i];
             dp[i][2]=max(dp[i][1],dp[i][2]);
             dp[i][1]=max(dp[i][0],dp[i][1]);
        }
        else
        {
             dp[i][0]+=a[i];
             dp[i][1]-=a[i];
             dp[i][2]+=a[i];
        }
        dp[i][1]=max(dp[i][2],dp[i][1]);
        dp[i][0]=max(dp[i][1],dp[i][0]);
     // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
    cout<<dp[n-1][0]<<endl;
}
