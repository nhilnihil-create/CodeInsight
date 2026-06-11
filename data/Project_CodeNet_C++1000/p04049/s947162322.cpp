#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2005;
int n,k,tot,lnk[maxn],son[maxn*2],nxt[maxn*2],ans,r;bool vis[maxn];
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
inline void add_e(int x,int y){tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;}
void DFS(int now,int fa,int dis)
{
	if(dis<=r) vis[now]=true;
	for(int i=lnk[now];i;i=nxt[i])
		if(son[i]!=fa)
			DFS(son[i],now,dis+1);
}
inline void Solve()
{
	if(k&1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=lnk[i];j;j=nxt[j])
			{
				memset(vis,0,sizeof(vis));
				DFS(i,0,0);
				DFS(son[j],0,0);
				int cnt=0;
				for(int t=1;t<=n;t++) if(!vis[t]) cnt++;
				if(cnt<ans) ans=cnt;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			DFS(i,0,0);
			int cnt=0;
			for(int t=1;t<=n;t++) if(!vis[t]) cnt++;
			if(cnt<ans) ans=cnt;
		}
	}
}
int main()
{
	n=read();k=read();ans=n;r=k>>1;
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add_e(a,b);add_e(b,a);
	}
	Solve();
	printf("%d\n",ans);
	return 0;
}