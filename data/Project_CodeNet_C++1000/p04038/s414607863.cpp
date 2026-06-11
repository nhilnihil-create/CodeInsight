#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,m,f[2005][2005],pn=4e6,fr[4000005],infr[4000005];
int C(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("1");
		return 0;
	}
	f[0][1]=1;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=addmod(f[i-1][j]+1ll*f[i][j-1]*C((n-i+1)+(m-1)*(n-j+2)-1,m-2)%mod);
			//printf("i=%d,j=%d,f=%d,C(%d,%d)=%d\n",i,j,f[i][j],(n-i+1)+(m-1)*(n-j+1)-1,m-2,C((n-i+1)+(m-1)*(n-j+1)-1,m-2));
		}
	}
	int ans=1ll*f[n+1][n]*fr[n]%mod;
	printf("%d",ans);
	return 0;
}