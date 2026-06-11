#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
int n,K,i,j,f[2005][2005],jc[4000005],rjc[4000005],inv[4000005];
int C(int n,int m)
{
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int main()
{
	scanf("%d%d",&n,&K);
	if(K==1)
	{
		printf("1");
		return 0;
	}
	inv[1]=1;
	for(i=2;i<=n*K;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=n*K;++i)
	{
		jc[i]=1ll*jc[i-1]*i%md;
		rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	}
	f[1][0]=1;
	for(i=1;i<=n;++i)
		for(j=0;j<=i;++j)
		{
			if(i<n)
				f[i+1][j]=(f[i+1][j]+f[i][j])%md;
			if(j<i)
				f[i][j+1]=(f[i][j+1]+1ll*f[i][j]*(n-j)%md*C(n*K-i-j*(K-1)-1,K-2))%md;
		}
	printf("%d",f[n][n]);
	return 0;
}
