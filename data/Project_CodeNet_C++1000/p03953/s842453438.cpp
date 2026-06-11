#include<bits/stdc++.h>
#define LL long long 
using namespace std;
LL n,m,k;
LL a[101001],to[101001],tmp,size,ans[101001],s[101001];
bool vis[101001];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		to[i]=i;
	}
	for(int i=n;i>=1;i--)a[i]-=a[i-1];
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&tmp);
		swap(to[tmp],to[tmp+1]);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		size=0;
		for(int j=i;!vis[j];j=to[j])
		{
			vis[j]=true;
			size++;
			s[size]=j;
		}
		for(int j=1;j<=size;j++)
		{
			ans[s[j]]=a[s[(k+j-1)%size+1]];
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		printf("%lld\n",ans[i]);
	}
	return 0;
}