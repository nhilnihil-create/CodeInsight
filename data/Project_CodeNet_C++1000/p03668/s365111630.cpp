#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 2e5;
using namespace std;
int n,edge[N * 2 + 5],nxt[N * 2 + 5],head[N + 5],edge_cnt,sg[N + 5];
void add_edge(int u,int v)
{
    edge[++edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt;
}
void dfs(int u,int fa)
{
    for (int i = head[u];i;i = nxt[i])
    {
        int v = edge[i];
        if (v == fa)
            continue;
        dfs(v,u);
        sg[u] ^= sg[v] + 2;
    }
}
int main()
{
    scanf("%d",&n);
    int u,v;
    for (int i = 1;i < n;i++)
    {
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1,0);
    if (sg[1])
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;
    return 0;
}