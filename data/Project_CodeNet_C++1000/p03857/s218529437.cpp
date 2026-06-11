#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 998244353
#define N 200005
int n,rd,rl;
vector<int> g[N],r[N],eki[N];
int vis[N],vis2[N],ans[N];
set<int> s;
void dfs1(int u,int cnt)
{
    vis[u]=cnt;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!vis[v]) dfs1(v,cnt);
    }
}
void dfs2(int u)
{
    vis2[u]=1;
    s.insert(vis[u]);
    eki[vis[u]].pb(u);
    for(int i=0;i<r[u].size();i++)
    {
        int v=r[u][i];
        if(!vis2[v]) dfs2(v);
    }
}
int main()
{
    fastio;
    cin>>n>>rd>>rl;
    for(int i=0;i<rd;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i=0;i<rl;i++)
    {
        int x,y;
        cin>>x>>y;
        r[x].pb(y);
        r[y].pb(x);
    }
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs1(i,cnt);
            cnt++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis2[i])
        {
            dfs2(i);
            for(auto it :s)
            {
                for(int j=0;j<eki[it].size();j++)
                {
                    ans[eki[it][j]]=eki[it].size();
                }
                eki[it].clear();
            }
            s.clear();
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<gap;
}
