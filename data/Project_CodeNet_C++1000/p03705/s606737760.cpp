#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
using namespace std;
int n,a,b;
signed main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	if (a>b)
	{
		printf("0\n");
		return 0;
	}
	if (a==b)
	{
		printf("1\n");
		return 0;
	}
	if (n==1)
	{
		printf("0\n");
		return 0;
	}
	printf("%lld\n",(b-a)*(n-2)+1);
}