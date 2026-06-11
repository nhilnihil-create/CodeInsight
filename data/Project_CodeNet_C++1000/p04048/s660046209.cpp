#include<cstdio>
long long n,x;
long long ans(long long n,long long x)
{
	if (n%x==0) return (2*(n/x)-1)*x;
	return ans(x,n%x)+2*(n/x)*x;
}
int main()
{
	while (~scanf("%lld%lld",&n,&x)) printf("%lld\n",ans(n-x,x)+n);
}