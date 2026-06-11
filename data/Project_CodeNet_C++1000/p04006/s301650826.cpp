#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
#define N 1000002
int n,x,a[N];
ll va[N];
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),va[i]=a[i];
	ll ans=1e18;
	for(int i=0;i<n;i++)
	{
		ll tsu=1ll*i*x;
		for(int j=1;j<=n;j++)
		{
			int fr=j-i;if(fr<1)fr+=n;
			va[j]=min(va[j],1ll*a[fr]);
			tsu+=va[j];
		}
		ans=min(ans,tsu);
	}
	printf("%lld\n",ans);
}
