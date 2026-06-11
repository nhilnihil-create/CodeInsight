#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<queue>
#define ll long long
using namespace std;
const int mod=1e9+7;
inline int read()
{
    int kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-')
        c=getchar(),x=-1;
    while(c>='0' && c<='9')
        kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
    return kkk*x;
}
ll n,K,dp[2001][2001],sum[4000001];
inline ll ksm(int a,int b)
{
	a%=mod;
	ll c=1;
	while(b)
	{
		if(b%2)
			c=1ll*c*a%mod;
		a=1ll*a*a%mod;
		b/=2;
	}
	//cout<<c<<endl;
	return c;
}
inline ll C(int N,int M)
{
	if(N==0)
		return 1;
	return 1ll*sum[M]*ksm(sum[N],mod-2)%mod*ksm(sum[M-N],mod-2)%mod;
}
inline void format()
{
	sum[0]=1;
	for(register int i=1;i<=4000000;++i)
		sum[i]=1ll*sum[i-1]*i%mod;
}
int main()
{
	format();
	n=read(),K=read();
	if(K==1)
	{
		puts("1");
		return 0;
	}
	for(register int i=0;i<=n;++i)
		dp[i][0]=1;
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=i;++j)
			dp[i][j]=(dp[i-1][j]+1ll*dp[i][j-1]*(n-j+1)%mod*C(K-2,n*K-i-(j-1)*(K-1)-1)%mod)%mod;
	printf("%lld\n",dp[n][n]);
	return 0;
}