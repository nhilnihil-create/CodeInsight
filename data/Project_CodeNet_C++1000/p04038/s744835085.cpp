#include<algorithm>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
int n,m,fac[4000010],ifc[4000010],dp[2010][2010];
int pow(int k,int i)
{
	int t=1;
	while(i)
	{
		if(i&1) t=1ll*t*k%mod;
		k=1ll*k*k%mod;i>>=1;
	}
	return t;
}
int C(int x,int y)
{
	if(x<y) return 0;
	return 1ll*fac[x]*ifc[y]%mod*ifc[x-y]%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1) {puts("1"); return 0;}
	fac[0]=1;dp[0][0]=1;
	for(int i=1;i<=n*m;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifc[n*m]=pow(fac[n*m],mod-2);
	for(int i=n*m-1;~i;--i) ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
		{
			dp[i][j]=dp[i-1][j];
			if(!j) continue;
			dp[i][j]=(dp[i][j]+1ll*dp[i][j-1]*C(n*m-i-(j-1)*(m-1)-1,m-2))%mod;
		}
	printf("%lld\n",1ll*dp[n][n]*fac[n]%mod);
	return 0;
}