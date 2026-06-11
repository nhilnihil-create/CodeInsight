#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=5005;
long long two=(mod+1)/2;
long long dp[maxn][maxn];
char shit[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",shit);
    int l=strlen(shit);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(dp[i][j]==0) continue;
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*2)%mod;
            dp[i+1][max(j-1,0)]=(dp[i+1][max(j-1,0)]+dp[i][j])%mod;
        }
    }
    long long ans=dp[n][l];
    for(int i=1;i<=l;i++)
        ans=ans*two%mod;
    printf("%d\n",ans);
    return 0;
}
