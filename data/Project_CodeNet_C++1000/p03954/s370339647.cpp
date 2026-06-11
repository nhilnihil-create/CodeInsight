#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
int a[MAXN*2],n;
bool check(int k)
{
	for(int i=0;i<n-1;i++)
	{
		int c1=0,c2=0;
		if(a[n-i]>=k&&a[n-i-1]>=k) c1++;
		if(a[n+i]>=k&&a[n+i+1]>=k) c1++;
		if(a[n-i]<k&&a[n-i-1]<k) c2++;
		if(a[n+i]<k&&a[n+i+1]<k) c2++;
		if(c1) return 1;
		if(c2) return 0;
	}
	return a[1]>=k;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;i++)
		scanf("%d",&a[i]);
	int l=2,r=2*n-1,ans=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
}