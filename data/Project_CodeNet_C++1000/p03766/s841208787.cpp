#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 1000005
#define M 200005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,fac[N],inv[N],ans,s[N],f[N];
int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo;
		}
		return sum;
}
int C(int x,int y)
{
		if (x==y) return 1;
		if (y==-1) return 0;
		return 1ll*fac[x]*inv[y]%Mo*inv[x-y]%Mo;
}
void jia(int &x,int y)
{
		x+=y; if (x>=Mo) x-=Mo;
}
int main()
{
	scanf("%d",&n);
	fac[0]=1; for (i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%Mo;
	for (i=0;i<=n;++i) inv[i]=power(fac[i],Mo-2);
	f[0]=1; s[0]=f[0];
	for (i=1;i<=n;++i)
	{
		f[i]=(s[i-1]-(i==1?0:f[i-2])+Mo)%Mo;
		s[i]=(s[i-1]+f[i])%Mo;
	}
	ans=f[n];
	jia(ans,1ll*f[n-1]*(n-1)%Mo);
	for (i=1;i<n;++i)
	{
		jia(ans,1ll*f[i-1]*i%Mo);
		jia(ans,1ll*f[i-1]*(n-1)%Mo*(n-1)%Mo);
	}
	printf("%d\n",ans);
}
