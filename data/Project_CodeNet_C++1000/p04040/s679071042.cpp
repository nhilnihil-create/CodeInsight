#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define maxn 201000

const LL mod=1e9+7;
LL jc[maxn],ny[maxn];
LL qpow(LL x,LL t)
{
	LL ret=1;
	while (t)
	{
		if (t&1) ret=ret*x%mod;
		x=x*x%mod;t>>=1;
	}
	return ret;
}
void pre()
{
	jc[0]=ny[0]=jc[1]=ny[1]=1LL;
	for (LL i=2;i<maxn;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		ny[i]=qpow(jc[i],mod-2);
		//if (i<=10) printf("%lld %lld %lld\n",i,jc[i],ny[i]);
	}
}
LL C(int n,int m)//C(n,m)
{
	//printf("%d %d\n",n,m);
	return jc[n]*ny[m]%mod*ny[n-m]%mod;
}
//10,4 10!/4!*6!
int mymin(int x,int y){return (x<y)?x:y;}
LL ct(int sx,int sy,int tx,int ty)
{
	//printf("%d %d %d %d\n",sx,sy,tx,ty);
	return C((tx-sx)+(ty-sy),mymin(tx-sx,ty-sy));
}
int main()
{
	int n,m,a,b,i;
	pre();LL ret=0;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for (i=b+1;i<=m;i++)
		ret=(ret+ct(1,1,n-a,i)*ct(n-a+1,i,n,m)%mod)%mod;
	printf("%lld\n",ret);
	return 0;
}
//n-a b+1 m
