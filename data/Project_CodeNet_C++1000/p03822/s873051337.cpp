#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define maxn 100010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int head[maxn],nxt[maxn*2],to[maxn*2],tot;
void add(int u,int v)
{
    tot++;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
}
int f[maxn];
void dfs(int x,int las)
{
    for(int i=head[x];i;i=nxt[i])
    {
        if(to[i]==las)  continue;
        dfs(to[i],x);
    }
    priority_queue<int>q;
    for(int i=head[x];i;i=nxt[i]){
        if(to[i]==las)  continue;
        q.push(f[to[i]]);
    }
    if(q.size()==0)  return;
    int now=0;
    while(q.size())
    {
        int tmp=q.top();
        q.pop();
        now++;
        f[x]=max(f[x],tmp+now);
    }
}
int main()
{
    n=read();
    for(int i=2;i<=n;i++)
    {
        int x=read();
        add(i,x);
        add(x,i);
    }
    dfs(1,0);
    printf("%d\n",f[1]);
    return 0;
}