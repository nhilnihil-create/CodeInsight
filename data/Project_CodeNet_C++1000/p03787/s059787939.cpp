#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
struct tyc{
	int to,next;
}e[4*N];
int head[N],n,m,size=0;
int x,y;
int oh,si,oth;
long long ans;
bool p=0;
bool vis[N],color[N];
void add(int x,int y)
{
	size++;
	e[size].to=y;
	e[size].next=head[x];
	head[x]=size;
}
void dfs(int x,int fa)
{
	//cout<<x<<endl;
	vis[x]=1;
	color[x]=color[fa]^1;
	for (int i=head[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if (y!=fa)
		{
			if (vis[y])
			{
				if (color[x]==color[y]) p=1;
				continue;
			}
			else dfs(y,x);
		}
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for (int i=1;i<=n;i++)
	{

		if (!vis[i])
		{
			if (head[i]==0) {si++,vis[i]=1;continue;}
			p=0;
			dfs(i,0);
			if (p) oh++;
			else oth++;
		}
	}
	//cout<<si<<" "<<oh<<" "<<oth<<endl;
//	cout<<2ll*si*n-1ll*si*si+((oth==1)?2:2ll*oth*(oth-1))+((oh==1)?1:1ll*oh*(oh-1))+2ll*oh*oth<<endl;
	ans=2ll*si*n-1ll*si*si+2ll*oth*oth+1ll*oh*oh+2ll*oh*oth;
	printf("%lld",ans);
}