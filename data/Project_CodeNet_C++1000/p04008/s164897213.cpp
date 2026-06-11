#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5;
int n,k,ans,tot;
vector<int>vr[maxn+8];
int pre[maxn+8],now[maxn+8],son[maxn+8],dep[maxn+8],fa[maxn+8];
bool vis[maxn+8];

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
    vr[dep[x]].push_back(x);
    for (int p=now[x];p;p=pre[p])
	{
	    int child=son[p];
	    fa[child]=x;dep[child]=dep[x]+1;
	    dfs(child);
	}
}

void solve(int x)
{
    for (int i=1;i<=k;i++)
	{
	    if (vis[x]) return;
	    vis[x]=1;
	    x=fa[x];
	}
    ans+=(x!=1);
}

int main()
{
    n=read(),k=read();
    int x=read();if (x!=1) ans=1;
    for (int i=2;i<=n;i++)
	{
	    int f=read();
	    add(f,i);
	}
    dfs(1);
    vis[1]=1;
    for (int i=n;i;i--)
	for (vector<int>::iterator it=vr[i].begin();it!=vr[i].end();it++)
	    solve(*it);
    printf("%d\n",ans);
    return 0;
}
