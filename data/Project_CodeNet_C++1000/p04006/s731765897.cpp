#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,pr,sum,ans,a[5050],minn[5050][5050];

int main()
{
	scanf("%lld%lld",&n,&pr);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",a+i);a[n+i]=a[i];ans+=a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			minn[i][0]=a[i];
			minn[i][j]=min(minn[i][j-1],a[n+i-j]);
		}
	}
	for(ll i=0;i<n;i++)
	{
		sum=pr*i;
		for(ll j=1;j<=n;j++)
		{
			sum+=minn[j][i];
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}