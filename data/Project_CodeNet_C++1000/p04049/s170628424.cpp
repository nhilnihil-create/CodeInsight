#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int N,K;
vector<int> adj[MAXN];
int dep[MAXN], cnt; //dep[i]记录以i为根的树的深度(根节点深度为0) 

void dfs(int u, int fa, int lim)
{
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v != fa)
        {
            dep[v] = dep[u] + 1; //深度+1 
            if(dep[v] > lim) cnt++;
            dfs(v,u,lim);
        }
    }
}

int main()
{
    scanf("%d%d",&N,&K);
    for(int i = 1; i < N; i++) //N个节点的树有N-1条边 
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0x3f3f3f3f;
    
    //枚举每一个点 
    if(K % 2 == 0)
    {
        for(int i = 1; i <= N; i++)
        {
            cnt = 0;
            dep[i] = 0; dfs(i,0,K/2); //fa[父节点] = 0 
            ans = min(ans,cnt);
        }
    }
    else
    {
    	//枚举每一条边，将树分为两棵 
        for(int i = 1; i <= N; i++)
            for(int j = 0; j < adj[i].size(); j++)
            {
                cnt = 0;
                dep[i] = 0; dfs(i,adj[i][j],(K-1)/2);
                dep[adj[i][j]] = 0; dfs(adj[i][j],i,(K-1)/2);
                ans = min(ans,cnt);
            }
    }

    printf("%d\n",ans);

    return 0;
}
