#include <bits/stdc++.h>
#define L long long

using namespace std;

struct S{
	L x,ord;
}a[100010];
L n;

struct P{
	L val,num,mi;
};

L ans[100010];
L stair[100010],stop;
L stairval[100010];
L stairsum[100010];
L stairsum2[100010];

int main()
{
	scanf("%lld",&n);
	L i;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].x);
		a[i].ord=i;
	}
	L ma=0;
	for(i=1;i<=n;i++)
	{
		if(a[i].x>ma)
		{
			ma=a[i].x;
			stair[++stop]=i;
			stairval[stop]=a[i].x;
		}
	}
	/*for(i=1;i<=stop;i++)
	{
		printf("%lld ",stairval[i]);
	}
	puts("");*/
	for(i=1;i<=n;i++)
	{
		L temp=upper_bound(stairval+1,stairval+stop+1,a[i].x)-stairval;
		stairsum[temp-1]++;
		stairsum2[temp]+=a[i].x-stairval[temp-1];
	}
	/*for(i=1;i<=stop;i++)
	{
		printf("%lld ",stairsum[i]);
	}
	puts("");*/
	for(i=stop;i>1;i--)
	{
		stairsum[i-1]+=stairsum[i];
	}
	for(i=1;i<=stop;i++)
	{
		ans[stair[i]]+=(stairval[i]-stairval[i-1])*stairsum[i]+stairsum2[i];
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld ",ans[i]);
	}
}