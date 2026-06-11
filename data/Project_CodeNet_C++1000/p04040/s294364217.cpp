#include <bits/stdc++.h>
using namespace std;

int h,w,a,b;
long long  jie[200010],ni[200010],ans;
const long long mod=1e9+7;
inline void exgcd(long long a,long long b,long long &x,long long &y)
{
	if(!b)
	{
		x=1;
		y=0;
	}
	else
	{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
int main()
{
	scanf("%d%d%d%d",&h,&w,&a,&b);
	jie[0]=1;
	for(int i=1;i<=h+w;++i)
	jie[i]=jie[i-1]*i%mod;
	long long x,y;
	exgcd(jie[h+w],mod,x,y);
	x=(x%mod+mod)%mod;
	if(!x)
	x+=mod;
	ni[0]=1;
	ni[h+w]=x;
	for(int i=h+w-1;i>=1;--i)
	ni[i]=ni[i+1]*(i+1)%mod;
	for(int i=1;i<=h-a;++i)
	{
		long long ji=ni[b-1]*ni[i-1]%mod*jie[b+i-2]%mod;
		ji=ji*ni[h-i]%mod*ni[w-b-1]%mod*jie[h-i+w-b-1]%mod;
		ans=(ans+ji)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}