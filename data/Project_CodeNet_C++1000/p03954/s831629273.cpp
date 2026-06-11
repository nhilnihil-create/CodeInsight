#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],b[N],n;
int work(int x)
{
	for(int i=1;i<=n*2-1;i++)
	{
		if(a[i]>=x) b[i]=1;
		else b[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		if(b[n-i]==b[n-i+1]) return b[n-i];
		if(b[n+i]==b[n+i-1]) return b[n+i];
	}
	return (n&1)^b[n]^1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;i++)
	{
		scanf("%d",a+i);
	}
	int l=1,r=n*2-1,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(work(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}