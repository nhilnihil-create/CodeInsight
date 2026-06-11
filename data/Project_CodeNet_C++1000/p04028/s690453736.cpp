#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
long long dp[11111],ddp[11111],n,sz;
char s[11111];
int main()
{
	scanf("%lld",&n);
	scanf("%s",s);
	sz=strlen(s);
	ddp[0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=sz+n;j++)
		{
			if (!j)
			{
				dp[j]=(ddp[j]+ddp[j+1]*2)%mod;
			}
			else dp[j]=(ddp[j-1]+ddp[j+1]*2)%mod;
		}
		for (int j=0;j<=sz+n;j++)
		{
			ddp[j]=dp[j];
		}
	}
	printf("%lld\n",dp[sz]);
	return 0;
}