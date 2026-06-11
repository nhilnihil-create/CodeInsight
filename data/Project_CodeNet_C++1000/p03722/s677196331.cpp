#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct bellford
{
    const long long INF=LLONG_MAX;
    struct edge{int u, v; ll w;};
    int nv, ne;
    vector<int> p;
    vector<ll>  d;
    vector<edge> E;

    bellford(int nv, int ne) :  nv(nv), ne(ne)
    {
        p.resize(nv, -1);
        d.resize(nv, INF);
    }

    void relax(int u, int v, ll w)
    {
        if(d[u]!=INF && d[v]>d[u]+w) d[v]=d[u]+w, p[v]=u;
    }

    bool get(int s)
    {
        d[s]=0;
        for(int i=0; i<nv-1; i++)
            for(auto  &e : E) relax(e.u, e.v, e.w);
        for(auto &e : E)
            if(d[e.v]>d[e.u]+e.w)
                return false;
        return true;
    }

    bool get(int s, int t)
    {
        d[s]=0;
        for(int i=0; i<nv; i++)
            for(auto  &e : E) 
                relax(e.u, e.v, e.w);

        vector<bool> visited(nv, false);
        visited[t]=true, t=p[t];
        while(t!=-1 && !visited[t])
        {
            visited[t]=true;
            t=p[t];
        }
        if(t==-1) return true;
        else return false;
    }
};

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    bellford g(N, M);
    for(int i=0; i<M; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g.E.push_back({a-1,b-1,-c});
    }
    if(g.get(0, N-1))
        printf("%lld\n", -g.d[N-1]);
    else
        printf("inf\n");
    return 0;
}