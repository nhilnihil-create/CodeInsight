#include<cstdio>
#define MAXN 100006
#include<algorithm>
using namespace std;
int n,m,id[MAXN],st[MAXN],top;
long long a[MAXN],ans[MAXN],k;
bool vis[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),id[i]=i;
	for(int i=n;i>=1;i--)
		a[i]-=a[i-1];
	scanf("%d%lld",&m,&k);
	for(int i=1,x;i<=m;i++)
		scanf("%d",&x),swap(id[x],id[x+1]);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			top=0;
			for(int j=i;!vis[j];j=id[j])
				st[++top]=j,vis[j]=1;
			for(int j=1;j<=top;j++)
				ans[st[j]]=a[st[(k+j-1)%top+1]];
		}
	for(int i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		printf("%lld\n",ans[i]);
	}
}