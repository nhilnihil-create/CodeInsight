#include<cstdio>
#define MOD 1000000007
int n,f[1000010];
int main()
{
	scanf("%d",&n);f[n]=n;f[n-1]=1ll*n*n%MOD;
	for(int i=n-2,s=0;i>0;--i)s=(s+f[i+3])%MOD,f[i]=(f[i+1]+1ll*(n-1)*(n-1)+s+i+1)%MOD;
	printf("%d\n",f[1]);return 0;
}
