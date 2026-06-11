#include<bits/stdc++.h>
#define MAXN 200005
#define reg register
#define inl inline
using namespace std;
int n,a[MAXN],ans;
inl bool Check(reg int mid)
{
	for(reg int i=0;i<n;i++)
	{
		if((a[n-i]<mid && a[n-i-1]<mid) || (a[n+i]<mid && a[n+i+1]<mid)) return 0;
		if((a[n-i]>=mid && a[n-i-1]>=mid) || (a[n+i]>=mid && a[n+i+1]>=mid)) return 1;
	}
	return a[n*2-1]>=mid;
}
int main()
{
	scanf("%d",&n);
	for(reg int i=1;i<=n*2-1;i++) scanf("%d",&a[i]);
	reg int l=1,r=n*2-1;
	while(l<=r)
	{
		reg int mid=l+r>>1;
		if(Check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}