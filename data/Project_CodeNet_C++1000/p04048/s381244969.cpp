#include<cstdio>
#define int long long
int n,m,x,a;
signed main()
{
	scanf("%lld%lld",&n,&m),a=n,n-=m;
	for(;m;)x=n%m,a+=n-x<<1,n=m,m=x;
	return printf("%lld",a-n),0;
}