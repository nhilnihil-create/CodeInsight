#include<bits/stdc++.h>

using namespace std;
int n,m,q;
const int MAXN=1e5+1e4;
vector<int> G[MAXN];
int dist[MAXN],v[MAXN],d[MAXN],c[MAXN],color[MAXN];
void dfs(int u,int Dl,int co)
{
    /* cout << u <<" "<< Dl << " "<< co << endl;
    for (int i=0;i<n;i++)cout << dist[i] <<ends;
    puts(""); */
    //if (Dl<=-1) return ;
    if (Dl<=dist[u]) return ;
    dist[u]=Dl;
    if (color[u]==0) color[u]=co;
    for (int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        dfs(v,Dl-1,co);
    }
}
int main()
{
    cin >> n >>m;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        --x,--y;
        G[x].push_back(y);
        G[y].push_back(x);
        color[i]=0;
    }
    memset(dist,-1,sizeof(dist));
    cin >> q;
    for (int i=0;i<q;i++)
    {
        cin >>v[i]>>d[i]>>c[i];
    }
    for (int i=q-1;i>=0;i--)
    {
        dfs(v[i]-1,d[i],c[i]);
    }
    for (int i=0;i<n;i++)
    {
        cout << color[i] <<endl;
    }
    return 0;
}
