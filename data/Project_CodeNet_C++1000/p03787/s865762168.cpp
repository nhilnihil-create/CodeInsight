#include<bits/stdc++.h>
using namespace std;
int n,m,I,P,Q;
int cnt,head[100010],to[400010],nxt[400010],linker[100010];
bool f,vis[100010];
void add(int x,int y)
{
	cnt++;
	to[cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int x,int fa)
{
	vis[x]=true;
	linker[x]=linker[fa]^1;
	for (int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if (y!=fa)
		{
			if (vis[y])
			{
				if (linker[x]==linker[y])
				{
					f=true;
				}
				continue;
			}
			else
			{
				dfs(y,x);
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	int x,y;
	for (int i=0;i<m;i++)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			if (!head[i])
			{
				I++;
				vis[i]=true;
				continue;
			}
			f=false;
			dfs(i,0);
			if (f)
			{
				P++;
			}
			else
			{
				Q++;
			}
		}
	}
	long long ans=2LL*I*n-1LL*I*I+1LL*P*P+2LL*P*Q+2LL*Q*Q;
	printf("%lld\n",ans);
    return 0;
}