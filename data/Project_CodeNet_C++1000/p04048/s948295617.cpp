#include<cstdio>
using namespace std;
long long ans;
long long dfs(long long a,long long b)
{
	if(b%a==0)
	{
		return b/a*a*3;  
	}
	return dfs(b%a,a)+b/a*a*3;
}
int main()
{
	long long n,x;
	scanf("%lld%lld",&n,&x);
	printf("%lld",dfs(x,n-x));
}