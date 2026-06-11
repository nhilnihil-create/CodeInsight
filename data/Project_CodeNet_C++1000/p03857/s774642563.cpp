#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
vector<vector<int> >g;
int p1[N],p2[N];
int n,m,k;
int findset(int p[],int u)
{
    if (p[u]<0) return u;
    else return p[u]=findset(p,p[u]);
}
void Union(int p[],int u, int v)
{
    if (p[u]>p[v]) swap(u,v);
    p[u]+=p[v];
    p[v]=u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    g.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        p1[i]=p2[i]=-1;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        int t=findset(p1,u);
        int s=findset(p1,v);
        if (t!=s) Union(p1,t,s);
    }
    for(int i=1;i<=k;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        int t=findset(p2,u);
        int s=findset(p2,v);
        if (t!=s) Union(p2,t,s);
    }
    map<pair<int,int>,int> mp;
    for(int u=1;u<=n;u++)
    {
        mp[make_pair(findset(p1,u),findset(p2,u))]++;
    }
    for(int u=1;u<=n;u++)
    {
        cout<<mp[make_pair(findset(p1,u),findset(p2,u))]<<' ';
    }
    return 0;
}
