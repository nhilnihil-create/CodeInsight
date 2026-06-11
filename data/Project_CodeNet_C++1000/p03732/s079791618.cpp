// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int dp[101][101][303],a[101],b[101],n,w,i,j,h,ans;
int main()
{
     scanf("%d%d",&n,&w);
     for(i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
     for(i=0;i<n;i++)
         {
             for(j=0;j<=i;j++)
                 {
                     for(h=0;h<=3*j;h++)
                         {
                             dp[i+1][j][h]=max(dp[i+1][j][h],dp[i][j][h]);
                             dp[i+1][j+1][h+a[i]-a[0]]=max(dp[i+1][j+1][h+a[i]-a[0]],dp[i][j][h]+b[i]);
                         }
                 }
         }
     for(i=0;i<=n;i++)
         {
             for(j=0;j<=3*i;j++)
                 {
                     long long s=(long long)a[0]*i+j;
                     if(s<=w)ans=max(ans,dp[n][i][j]);
                 }
         }
     printf("%d\n",ans);return 0;
}