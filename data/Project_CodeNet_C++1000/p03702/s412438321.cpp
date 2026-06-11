#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MOD(x) ((x)%mod)
long long n,a,b;
long long h[100005];
bool check(long long x)
{
	long long num=0;
	for(int i=1;i<=n;i++)
	{
		if(h[i]<=x*b) continue;
		long long tmp;
		tmp=(h[i]-x*b)/a;
		if(tmp*a!=h[i]-x*b) tmp++;
		num+=tmp;
	}
	if(num>x) return 0;
	return 1;
}
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	a-=b;
	for(int i=1;i<=n;i++)
		scanf("%lld",&h[i]);
	long long l=1,r=1e9;
	long long m;
	while(l<r)
	{
		m=(l+r)/2;
		if(check(m)) r=m;
		else l=m+1;
	}
	printf("%lld",l);
	return 0;
}