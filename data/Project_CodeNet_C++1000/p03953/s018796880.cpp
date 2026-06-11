#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
int a[100010],b[100010],n,m,k,sum,tmp[100010];
void power(int k)
{
	while(k)
	{
		if(k&1)
		{
			for(int i=1;i<=n;i++)tmp[i]=a[b[i]];
			for(int i=1;i<=n;i++)a[i]=tmp[i];
		}
		for(int i=1;i<=n;i++)tmp[i]=b[b[i]];
		for(int i=1;i<=n;i++)b[i]=tmp[i];
		k>>=1;
	}
	return;
}
signed main()
{
//	freopen("qwq.in","r",stdin);
//	freopen("qwq.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=i;
	for(int i=n;i>=1;i--)a[i]=a[i]-a[i-1];
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%lld",&x);
		swap(b[x],b[x+1]);
	}
	power(k);
	for(int i=1;i<=n;i++)sum=sum+a[i],printf("%lld.0\n",sum);
}