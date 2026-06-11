#include<bits/stdc++.h>

using namespace std;
const int MAXN=1e5+1e4;
int n,dist[2][MAXN],d[MAXN],vis[MAXN];
vector<int> G[MAXN];
void bfs(int beg)
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    q.push(beg);
    vis[beg]=1;
    d[beg]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<G[u].size();i++)
        {
            if (!vis[G[u][i]])
            {
                vis[G[u][i]]=1;
                q.push(G[u][i]);
                d[G[u][i]]=d[u]+1;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        --x,--y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs(0);
    memcpy(dist[0],d,sizeof(d));
    bfs(n-1);
    memcpy(dist[1],d,sizeof(d));
    int sumF=0,sumS=0;
    for (int i=0;i<n;i++)
    {
        if (dist[0][i]<=dist[1][i]) ++sumF;
        else                        ++sumS;
    }
    if (sumF>sumS)
    {
        cout << "Fennec" << endl;
    }else
    {
        cout << "Snuke" << endl;
    }
    return 0;
}
