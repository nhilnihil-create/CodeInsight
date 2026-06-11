#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,cnt,last[N],sg[N];
struct edge{int to,next;}e[N*2];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void addedge(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x,int fa)
{
    for (int i=last[x];i;i=e[i].next)
    {
        if (e[i].to==fa) continue;
        dfs(e[i].to,x);
        sg[x]^=sg[e[i].to]+1;
    }
}

int main()
{
    n=read();
    for (int i=1;i<n;i++)
    {
        int x=read(),y=read();
        addedge(x,y);
    }
    dfs(1,0);
    if (sg[1]) puts("Alice");
    else puts("Bob");
    return 0;
}
