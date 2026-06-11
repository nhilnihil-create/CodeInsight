#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;
int n,a[maxn],b[maxn],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
		ans+=((a[i]^i)&1);
	}
	printf("%d",ans/2);
	return 0;
}