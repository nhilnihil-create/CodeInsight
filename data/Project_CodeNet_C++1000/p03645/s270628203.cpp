#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fr first
#define sc second
#define N 300009
#define inf 2e16
#define pi pair<ll,ll>
#define pb push_back
using namespace std;
typedef long long ll;
void slv()
{
}
vector<int>adj[N];
bool vis[N];
int dis[N];
void vfs(int s)
{
    queue<int>q;
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vfs(1);
    if(dis[n]==2) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
    return 0;
}
