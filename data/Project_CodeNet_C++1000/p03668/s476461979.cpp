#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
vector<int> edge[MAXN];
int n,sg[MAXN],u,v;
void dfs(int u,int fa)
{
    sg[u]=0;
    for(auto v : edge[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        sg[u]^=sg[v]+1;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    puts(sg[1]?"Alice":"Bob");
}