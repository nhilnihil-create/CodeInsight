#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=2010;
const int mod=1000000007;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int n,k,f[Maxn][Maxn];
int fac[Maxn*Maxn],inv[Maxn*Maxn],fin[Maxn*Maxn];
void pre()
{
	fac[0]=1;
	for(int i=1;i<=n*k;i++)fac[i]=(LL)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n*k;i++)inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
	fin[0]=1;
	for(int i=1;i<=n*k;i++)fin[i]=(LL)fin[i-1]*inv[i]%mod;
}
int C(int n,int m)
{
	if(n<m)return 0;
	return (LL)fac[n]*fin[m]%mod*fin[n-m]%mod;
}
int main()
{
	n=read(),k=read();
	if(k==1)return puts("1"),0;
	pre();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=i;j++)
	{
		f[i][j]=f[i-1][j];
		if(j)f[i][j]=(f[i][j]+(LL)(n-(j-1))*f[i][j-1]%mod*C(n-i+(n-(j-1))*(k-1)-1,k-2)%mod)%mod;
	}
	printf("%d",f[n][n]);
}