#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a,b,c,d,e;scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
	long long ans=0;
	if(a>0&&d>0&&e>0)
	{
		a--;d--;e--;ans=max(ans,a/2*2+b+d/2*2+e/2*2+3);a++;d++;e++;
	}
	ans=max(ans,a/2*2+b+d/2*2+e/2*2);
	printf("%lld",ans);
	return 0;
 } 