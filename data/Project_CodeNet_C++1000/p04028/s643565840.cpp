#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int dp[5005][5005];
char s[5005];
typedef long long ll;
ll qmod(ll a,ll b)
{
    ll ans=1;
	while(b)
    {
        if(b&1)
        {
            ans=(a*ans)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int main()
{
	int n;
	cin>>n;
	scanf("%s",s);
	int m=strlen(s);
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i+1][j+1]=(0ll+dp[i+1][j+1]+2ll*dp[i][j])%mod;
			dp[i+1][max(0,j-1)]=(0ll+dp[i+1][max(0,j-1)]+dp[i][j])%mod;
		}
	}
	cout<<dp[n][m]*qmod(qmod(2,m),mod-2)%mod<<endl;
	return 0;
}