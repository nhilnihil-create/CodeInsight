#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int n,head[M],num_edge;
struct Edge
{
    int to;
    int Next;
    int dis;
}edge[M<<2];
void add_edge(int from,int to)
{
    edge[++num_edge].to=to;
    edge[num_edge].Next=head[from];
    head[from]=num_edge;
}
int son[M],cnt,dis[M];
int dfs(int x,int fa)
{
    bool flag;
    if(x==n)
        flag=true;
    else
        flag=false;
    for(int i=head[x];i;i=edge[i].Next)
    {
        int y=edge[i].to;
        if(y==fa)
            continue;
        flag=flag|dfs(y,x);
    }
    son[fa]=son[fa]+son[x]+1;
    if(flag)
    {
        dis[++cnt]=x;
        return 1;
    }
    return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(1,0);
    long long ans=0;
    for(int i=cnt;i>cnt/2;i--)
        ans=ans+son[dis[i]]-son[dis[i-1]];
    if(ans*2>n)
        puts("Fennec");
    else
        puts("Snuke");
    return 0;
}