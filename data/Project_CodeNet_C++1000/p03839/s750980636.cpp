#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans,a[101010],sum[101010],youzhen[101010],zuozhen[101010];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		zuozhen[i]=zuozhen[i-1]+max(a[i],0ll);
	}
	for(int i=n;i>=1;i--)
	{
		youzhen[i]=youzhen[i+1]+max(a[i],0ll);
	}
	for(int i=0;i<=n-k;i++)
	{
		ans=max(ans,zuozhen[i]+youzhen[i+k+1]+max(sum[i+k]-sum[i],0ll));
	}
	cout<<ans<<endl;
	return 0;
}
