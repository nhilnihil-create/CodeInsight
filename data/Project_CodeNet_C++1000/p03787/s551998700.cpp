#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5;
const int maxm=2e5;
int n,m,flag,tot;
ll c,p,d,ans;
int pre[maxm*2+8],now[maxn+8],son[maxm*2+8];
bool vis[maxn+8],color[maxn+8];

int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

void add(int u,int v)
{
    pre[++tot]=now[u];
    now[u]=tot;
    son[tot]=v;
}

void dfs(int x)
{
    vis[x]=1;
    for (int p=now[x];p;p=pre[p])
	{
	    int child=son[p];
	    if (!vis[child])
		{
		    color[child]=color[x]^1;
		    dfs(child);
		}
	    else
		    if (color[child]^color[x]^1) c-=flag,d+=flag,flag=0;
	}
}

int main()
{
    n=read(),m=read();
    for (int i=1;i<=m;i++)
	{
	    int u=read(),v=read();
	    add(u,v);
	    add(v,u);
	}
    for (int i=1;i<=n;i++)
	if (!now[i]) p++;
	else if (!vis[i]) flag=1,c++,dfs(i);
    ans=p*n+p*(n-p)+d*d+c*(d+c)*2;
    printf("%lld\n",ans);
    return 0;
}
    
