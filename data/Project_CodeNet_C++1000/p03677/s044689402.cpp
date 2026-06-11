#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[202020];
long long ans,res,sum[202020];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int l=a[i],r=a[i+1];
		if(l>r) r+=m;
		ans+=r-l;
		l+=2;
		if(l>r) continue;
		sum[l]++;sum[r+1]-=r-l+2;sum[r+2]+=r-l+1;
	}
	for(int i=1;i<=m+m;i++)
		sum[i]+=sum[i-1];
	for(int i=1;i<=m+m;i++)
		sum[i]+=sum[i-1];
	res=ans;
	for(int i=1;i<=m;i++)
		res=min(res,ans-sum[i]-sum[i+m]);
	printf("%lld\n",res);
	return 0;
}