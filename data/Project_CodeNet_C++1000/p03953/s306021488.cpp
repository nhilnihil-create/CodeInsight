#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;


ll n,m,pos[maxn],k,ans[maxn];
ll a[maxn],b[maxn],st[maxn];
ll move[maxn],vis[maxn];



int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&pos[i]);
	for(int i=1;i<=n;i++)
		b[i]=pos[i]-pos[i-1],a[i]=i;
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		ll x;
		scanf("%lld",&x);
		swap(a[x],a[x+1]);
	}
	for(int t=1;t<=n;t++)
	{
		if(vis[t])continue;
		int round = 0;
		for(int i=t;!vis[i];i=a[i])vis[i]=1,st[++round]=i;
		for(int i=1;i<=round;i++) ans[st[i]] = b[ st[(i+k-1)%round +1]];
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		printf("%.1lf\n",(double)ans[i]);
	}
	return 0;
}