#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 4000010
#define M 2010
#define mod 1000000007
#define ll long long
using namespace std;
ll fac[N],inv[N],f[M][M];
ll ksm(ll a,ll b=mod-2)
{
	if(b==0) return 1;
	if(b==1) return a;
	ll q=ksm(a,b>>1);
	if(b&1) return q*q%mod*a%mod;
	return q*q%mod;
}
ll C(int a,int b){if(b>a || b<0) return 0;return fac[a]*inv[b]%mod*inv[a-b]%mod;}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==1){puts("1");return 0;}
	fac[0]=1;
	for(int i=1;i<=N-10;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-10]=ksm(fac[N-10]);
	for(int i=N-11;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			const int r=n-i+(n-j+1)*(m-1)-1;
			f[i][j]=f[i-1][j]+(j?f[i][j-1]*(n-j+1)%mod*C(r,m-2):0);
			f[i][j]%=mod;
		}
	printf("%lld",f[n][n]);
	return 0;
}
