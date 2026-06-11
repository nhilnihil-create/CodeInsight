#include<iostream>
#include<cstdio>
#define N (200000+1000)
using namespace std;

int n,a[N],l,r,ans,mid;
int g(int x){return x>mid;}

int check(int x)
{
	for (int i=1; i<=n-1; ++i)
	{
		if (g(a[n-i+1])==g(a[n-i])) return g(a[n-i]);
		if (g(a[n+i-1])==g(a[n+i])) return g(a[n+i]);
	}
	return g(a[1]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=2*n-1; ++i)
		scanf("%d",&a[i]);
	l=1; r=2*n-1; ans=-1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (!check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}