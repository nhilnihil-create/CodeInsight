#include<complex>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
const int N=2e3+7;
int n,m;
int f[N][N],fac[N*N],finv[N*N];
int Fpow(long long b,int p)
{
	long long res=1;
	for(;p;p>>=1,b=b*b%mod)
		if(p&1)res=res*b%mod;
	return res;
}
void Init()
{
	fac[0]=finv[0]=1;
	for(int i=1;i<=n*m;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	finv[n*m]=Fpow(fac[n*m],mod-2);
	for(int i=n*m-1;i;i--)
		finv[i]=1ll*finv[i+1]*(i+1)%mod;
}
int C(int n,int m)
{
	return 1ll*fac[n]*finv[m]%mod*finv[n-m]%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1){printf("1\n");return 0;}
	Init();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			if(j)f[i][j]=(f[i][j]+1ll*f[i][j-1]*(n-j+1)%mod*C(n*m-i-(j-1)*(m-1)-1,m-2))%mod;
		}
	printf("%d\n",f[n][n]);
	return 0;
}