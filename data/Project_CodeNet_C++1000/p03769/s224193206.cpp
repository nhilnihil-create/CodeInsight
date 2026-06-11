#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 110
#define LL long long
int a[MAXN*2],l=MAXN,r=MAXN,ls=0;
void dfs(LL N)
{
	if(N==1)
	{
		a[l]=++ls;
		return;
	}
	if(N%2)
	{
		dfs(N/2);
		a[++r]=++ls;
	}
	else
	{
		dfs(N-1);
		a[--l]=++ls;
	}
}
LL n;
int main()
{
	scanf("%lld",&n);
	dfs(n);
	printf("%d\n",ls*2);
	for(int i=l;i<=r;i++)
		printf("%d ",a[i]);
	for(int i=1;i<=ls;i++)
		printf("%d ",i);
}