#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int N = 1e5+10;
const ll INF = 1e15;

using namespace std;

vector<pair<int,ll>> Graph[N];
vector<ll> d;

void dijkstra (int k, int n)
{
    d.assign(n+1,INF);
    d[k]=0;
    set<int> q;
    q.insert(k);
    while (!q.empty())
    {
        int v=*q.begin();
        q.erase(q.begin());
        for (auto e: Graph[v])
        {
            int to=e.ff;
            ll len=e.ss;
            if (d[to]>d[v]+len)
            {
                d[to]=d[v]+len;
                q.insert(to);
            }
        }
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
        Graph[a].pb(mp(b,c));
        Graph[b].pb(mp(a,c));
    }
    cin>>q>>k;
    dijkstra(k,n);
    int x,y;
    while (q--)
    {
        cin>>x>>y;
        cout<<d[x]+d[y]<<endl;
    }
}