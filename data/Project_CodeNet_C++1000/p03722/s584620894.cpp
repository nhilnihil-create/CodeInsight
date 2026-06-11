#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct bellford
{
    const ll INF=LLONG_MAX;
    struct edge {int u, v; ll w;};
    int nv, ne;
    vector<ll> d;
    vector<int> p;
    vector<edge> E;
 
    bellford(int nv, int ne) : nv(nv), ne(ne)
    {
        d.resize(nv, INF);
        p.resize(nv,-1);
    }
 
    void relax(int u, int v, ll w)
    {
        if(d[u]!=INF && d[v]>d[u]+w)
        {
            d[v]=d[u]+w;
            p[v]=u;
        }
    }
 
    bool get(int s)
    {
        d[s]=0; 
        for(int i=0; i<nv; i++)
            for(auto &e : E)
                relax(e.u, e.v, e.w);
 
        vector<bool> path(nv, false);
        path[nv-1]=true;
        int v=p[nv-1];
        while(v!=-1 && !path[v])
        {
            path[v]=true;
            v=p[v];
        }
        if(v!=-1) return false;
        return true;
    }
};
 
 
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    bellford g(N, M);
    for(int i=0; i<M; i++)
    {
        int a, b;
        ll c;
        scanf("%d%d%lld", &a, &b, &c);
        g.E.push_back({a-1, b-1, -c});
    }
    if(g.get(0)) printf("%lld\n", -g.d[N-1]);
    else printf("inf\n");
    return 0;
}