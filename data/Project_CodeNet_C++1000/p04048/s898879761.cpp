#include<cstdio>
#include<algorithm>
using namespace std;
long long ans=0;
long long dfs(long long a,long long b)
{
	if (b==0) return ans-=a;
	ans+=a/b*b*2;
	return dfs(b,a%b);
}
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	ans+=n;
	n=n-m;
	if (n<m) swap(n,m);
	dfs(n,m);
	printf("%lld",ans);
	return 0;
}