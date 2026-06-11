#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a;
    cin>>n>>a;
    ll b[60];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    ll dp[5000][5000];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            for(int k=0;k<=2500;k++)
            {
                dp[j+1][k+b[i]]+=dp[j][k];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=dp[i][a*i];
    }
    cout<<ans;
    return 0;
}





