#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long MAXN=100005;
long long n,m,k,top;
long long a[MAXN],id[MAXN],st[MAXN],ans[MAXN];
bool vis[MAXN];
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		id[i]=i;
	}
	for(long long i=n;i>=1;i--)
		a[i]-=a[i-1];
	scanf("%lld %lld",&m,&k);
	for(long long i=1;i<=m;i++)
	{
		long long x;
		scanf("%lld",&x);
		swap(id[x],id[x+1]);
	}
	for(long long i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			top=0;
			for(long long j=i;!vis[j];j=id[j])
			{
				st[++top]=j;
				vis[j]=1;
			}
			for(long long j=1;j<=top;j++)
			{
				ans[st[j]]=a[st[(k+j-1)%top+1]];
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		printf("%lld\n",ans[i]);
	}
}