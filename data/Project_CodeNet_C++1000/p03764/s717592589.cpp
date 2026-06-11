#include <iostream>
using namespace std;
#define mod 1000000007
long long solve(int n)
{
	long long sum=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		sum+=a;
		ans=(ans+1LL*i*a-sum)%mod;
	}
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	long long x=solve(n),y=solve(m);
	printf("%lld",(x*y)%mod);
}