#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
int n,l,r,a[maxn];
bool check(int x)
{
	for(int i=0;i<n-1;i++)
	{
		bool x1=0,x2=0;
		if(a[n-i]>=x&&a[n-i-1]>=x) x1=true;
		if(a[n+i]>=x&&a[n+i+1]>=x) x1=true;
		if(a[n-i]<x&&a[n-i-1]<x) x2=true;
		if(a[n+i]<x&&a[n+i+1]<x) x2=true;
		if(x1) return true;
		if(x2) return false;
	}
	return a[1]>=x;
}
int BS()
{
	int l=1,r=n*2+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;i++) scanf("%d",&a[i]);
	printf("%d\n",BS());
}