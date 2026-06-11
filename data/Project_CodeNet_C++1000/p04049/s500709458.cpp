#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=2010;
const int inf=2147483647;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int n,k;
struct Edge{int y,next;}e[Maxn<<1];
int last[Maxn],len=0;
void ins(int x,int y)
{
	int t=++len;
	e[t].y=y;e[t].next=last[x];last[x]=t;
}
int f[Maxn][Maxn],g[Maxn],sz[Maxn],ans=inf;
void dfs(int x,int ff)
{
	sz[x]=1;f[x][k]=n;
	for(int i=last[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==ff)continue;
		dfs(y,x);
		for(int j=1;j<k;j++)
		g[j]=min(f[x][j]+f[y][min(k-j-1,j-1)],f[x][min(k-j,j)]+f[y][j-1]);
		f[x][k]=min(f[x][k]+sz[y],sz[x]-1+f[y][k-1]);
		sz[x]+=sz[y];
		f[x][0]+=f[y][0]+1;
		for(int j=2;j<k;j++)g[j]=min(g[j],g[j-1]);
		for(int j=1;j<k;j++)f[x][j]=g[j];
	}
//	for(int i=0;i<=k;i++)
//	printf("f[%d][%d]=%d\n",x,i,f[x][i]);puts("");
	for(int i=1;i<=k;i++)ans=min(ans,n-sz[x]+f[x][i]);
}
int main()
{
//	freopen("wa.txt","r",stdin);
	memset(f,0,sizeof(f));
	n=read(),k=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y),ins(y,x);
	}
	dfs(1,0);
	printf("%d",ans);
}