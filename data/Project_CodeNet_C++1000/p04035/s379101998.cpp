#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int n;
long long L,a[maxn];
int main()
{
	scanf("%d%lld",&n,&L);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]+a[i+1]>=L)
		{
			printf("Possible\n");
			for(int j=n-1;j>=i+1;j--) printf("%d\n",j);
			for(int j=1;j<i;j++) printf("%d\n",j);
			printf("%d\n",i);
			return 0;
		}
	}
	printf("Impossible");
	return 0;
}