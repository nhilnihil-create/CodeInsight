#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool dp[5010];
int n,k;
bool check(int mid)
{
	if(a[mid]>k)return 1;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i==mid)continue;
		for(int j=k;j>=a[i];j--)
		dp[j]=dp[j]||dp[j-a[i]];
	}
	for(int i=k-a[mid];i<k;i++)
	if(dp[i])return true;
	return false;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<r;
	return 0;
}