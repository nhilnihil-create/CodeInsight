#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=2009,MOD=1e9+7;
LL n,k;
LL fac[N*N],invfac[N*N],f[N][N];
template<typename T>
inline void read(T &x)
{
	x=0;T w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';	c=getchar();}
	x*=w;
}
LL qpow(LL a,LL b,LL p)
{
	LL x=a,ans=1;
	while(b)
	{
		if(b&1)	ans=ans*x%p;
		x=x*x%p;
		b>>=1;
	}
	return ans%p;
}
LL inv(LL a,LL p)
{
	return qpow(a,p-2,p);
}
LL C(LL n,LL m)
{
	return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}
void init(LL n)
{
	fac[0]=1;
	for(LL i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%MOD;
	invfac[n]=inv(fac[n],MOD);
	for(LL i=n-1;i>=0;--i)
		invfac[i]=invfac[i+1]*(i+1)%MOD;
}
int main()
{
	read(n);read(k);
	if(k==1)
	{
		printf("1");
		return 0;
	}
	init(n*k);
	f[0][0]=1;
	for(LL i=0;i<=n;++i)
		for(LL j=max(i,1ll);j<=n;++j)
			f[i][j]=((i?f[i-1][j]:0)+f[i][j-1]*C(i+j*(k-1)-1,k-2))%MOD;
	printf("%lld",f[n][n]*fac[n]%MOD);
	return 0;
}