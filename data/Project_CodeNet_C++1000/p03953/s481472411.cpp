#include<cstdio>
#define LL long long
#define maxn 100005
int n,m,id[maxn],st[maxn],tp;
LL k,x[maxn],ans[maxn];
bool vis[maxn];
void swap(int &a,int &b) { int t=a; a=b; b=t; }
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=n;i;i--) x[i]-=x[i-1],id[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		int a;
		scanf("%d",&a);
		swap(id[a],id[a+1]);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			tp=0;
			for(int j=i;!vis[j];j=id[j]) st[++tp]=j,vis[j]=true;
			for(int j=1;j<=tp;j++) ans[st[j]]=x[st[(k+j-1)%tp+1]];
		}
	for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
	for(int i=1;i<=n;i++) printf("%lld.0\n",ans[i]);
}
