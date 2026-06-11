#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int N = 1e5+10;

struct edge
{
    int to;
    ll len;
} ng1,ng2;

using namespace std;

vector<edge> Graph[N];
ll depth[N];

void dfs (int v, int p, ll d)
{
    depth[v]=d;
    for (auto e: Graph[v])
    {
        if (e.to==p)
            continue;
        dfs(e.to,v,d+e.len);
    }
}

main()
{
    fast;
    int n,a,b,q,k,i;
    ll c;
    cin>>n;
    for (i=0;i<n-1;i++)
    {
        cin>>a>>b>>c;
        //struct edge ng1,ng2;
        ng1.to=b;
        ng2.to=a;
        ng1.len=c;
        ng2.len=c;
        Graph[a].pb(ng1);
        Graph[b].pb(ng2);
    }
    cin>>q>>k;
    dfs(k,-1,0);
    int x,y;
    while (q--)
    {
        cin>>x>>y;
        cout<<depth[x]+depth[y]<<endl;
    }
}