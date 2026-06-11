#include <cstdio>
#define ll long long
#define rep(i,j,k) for (i=j;i<=k;i++)
#define down(i,j,k) for (i=j;i>=k;i--)
using namespace std;
const int N=2e3+5,B=4e6+5,mod=1e9+7;
int n,k,i,j,ans,f[N][N],fac[B],inv[B];
int fgm(int a,int n)
{
	int ret=1,bsc=a;
	for (;n>0;n>>=1,bsc=(ll)bsc*bsc%mod)
	if (n&1) ret=(ll)ret*bsc%mod;
	return ret;
}
int C(int n,int m)
{
	if (n<m) return 0;
	if (!m || !(n-m)) return 1;
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
//	freopen("leftmost.in","r",stdin);
//	freopen("leftmost.out","w",stdout);
	scanf("%d%d",&n,&k);
	if (k==1) {
		printf("1\n"); return 0;
	}

	fac[1]=fac[0]=inv[1]=inv[0]=1; 
	rep(i,2,n*k) fac[i]=(ll)fac[i-1]*i%mod;
	inv[n*k]=fgm(fac[n*k],mod-2);
	down(i,n*k-1,2)	inv[i]=(ll)(i+1)*inv[i+1]%mod;
	
	f[0][0]=1;
	rep(i,0,n)
		rep(j,i,n)
		{
			if (i>0) f[i][j]=f[i-1][j];
			if (j>0 && i<j) f[i][j]=(f[i][j]+(ll)f[i][j-1]*C(j*(k-1)+i-1,k-2) )%mod;
		}
	ans=(ll)f[n][n]*fac[n]%mod;
	printf("%d\n",ans);
	return 0;
}