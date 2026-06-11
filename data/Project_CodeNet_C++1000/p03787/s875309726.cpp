#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long LL;
int read()
{
    char c=getchar();int f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n,m;
int head[maxn],nex[maxn<<2],to[maxn<<2],cnt,col[maxn];
void add(int u,int v)
{
	to[++cnt]=v;nex[cnt]=head[u];head[u]=cnt;
}
LL I,p,q;
bool vis[maxn],flag;
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=nex[i])
	{
		if(!vis[to[i]]) col[to[i]]=col[x]^1,dfs(to[i]);
		else if(col[to[i]]==col[x]) flag=1; 
	}
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		flag=0;
		if(!head[i]) I++;
		else if(!vis[i])
		{
			dfs(i);
			if(flag) p++;
			else q++;
		}
	}
	printf("%lld\n",I*I+I*(n-I)*2+p*q*2+p*p+q*q*2);
	return 0;
}
