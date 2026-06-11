#include<bits/stdc++.h>
using namespace std;
const int mx=1e6;
vector<int>adj[mx];
bool visited[mx];
queue<int>q;
int level[mx];
void bfs(int x)
{
    q.push(x);
    visited[x]=1;
    level[x]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!visited[v])
            {
                q.push(v);
                level[v]=level[u]+1;
                visited[v]=1;
            }
        }
    }
}
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited,0,sizeof(visited));
    bfs(1);
    if(level[n]==2)cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}
