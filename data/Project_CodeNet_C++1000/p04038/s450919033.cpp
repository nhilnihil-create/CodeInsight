#include<cstdio>
#define mo 1000000007
int fac[4000005],inv[4000005],n,k,f[2005][2005];
int C(int n,int m){return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
int ksm(int a,int p)
{int ans=1;for(;p;p>>=1,a=1ll*a*a%mo)if(p&1)ans=1ll*ans*a%mo;return ans;}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1){printf("1\n");return 0;}
	f[0][0]=1;inv[0]=fac[0]=1;
	for(int i=1;i<=n*k;i++)fac[i]=fac[i-1]*1ll*i%mo;
	inv[n*k]=ksm(fac[n*k],mo-2);
	for(int i=n*k-1;i;i--)inv[i]=inv[i+1]*1ll*(i+1)%mo;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0];
	 	for(int j=1;j<=i;j++)
	  	 f[i][j]=(f[i-1][j]+f[i][j-1]*1ll*C(n*k-(j-1)*(k-1)-i-1,k-2)%mo)%mo;
	}printf("%d\n",f[n][n]*1ll*fac[n]%mo);
}