#include <bits/stdc++.h>
using namespace std;
long long cum[100005],cumz[100005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		cum[i]=cum[i-1]+a;
		cumz[i]=cumz[i-1]+max(a,0);
	}
	long long ans=0;
	for (int i=0;i<=n-k;i++)
	ans=max(ans,cumz[n]-(cumz[i+k]-cumz[i])+max(0LL,cum[i+k]-cum[i]));
	printf("%lld",ans);
}