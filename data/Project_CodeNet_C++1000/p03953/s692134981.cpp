//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define db double
#define inf 20021225
#define N 100010
using namespace std;
int n,m,to[N],stk[N]; ll k,a[N],x[N],nw[N],ans[N]; bool vis[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%lld",&x[i]),nw[i]=x[i]-x[i-1],to[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++)	scanf("%lld",&a[i]),swap(to[a[i]],to[a[i]+1]);
	for(int i=1;i<=n;i++)	if(!vis[i])
	{
		int cnt=0;
		for(int j=i;!vis[j];j=to[j])
			vis[j]=1,stk[++cnt]=j;
		for(int j=1;j<=cnt;j++)
			ans[stk[j]]=nw[stk[(j+k-1)%cnt+1]];
	}
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1],printf("%lld\n",ans[i]);
	return 0;
}