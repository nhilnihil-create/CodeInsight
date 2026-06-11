/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
 
#include <bits/stdc++.h>
using namespace std;
 
const int mx=1e5+5;
vector <int> tree[mx];
int cnt,level[mx],dist[mx];
bool vis[mx];
void bfs1 ()
{
    memset(vis,0,sizeof(vis));
    queue<int> myQ;
    myQ.push(1);
    level[1]=0;
    vis[1]=true;
    int m;
    while (!myQ.empty()) {
        int u=myQ.front();
        myQ.pop();
        m=tree[u].size();
        for (int i=0;i<m;i++) {
            int v=tree[u][i];
            if (vis[v]) continue;
            vis[v]=true;
            level[v]=1+level[u];
            myQ.push(v);
        }
    }
}
void bfs2(int n)
{
    memset(vis,0,sizeof(vis));
    queue<int> myQ;
    myQ.push(n);
    dist[n]=0;
    vis[n]=true;
    int m;
    while (!myQ.empty()) {
        int u=myQ.front();
        if (dist[u]<level[u]) cnt++;
        myQ.pop();
        m=tree[u].size();
        for (int i=0;i<m;i++) {
            int v=tree[u][i];
            if (vis[v]) continue;
            vis[v]=true;
            dist[v]=1+dist[u];
            myQ.push(v);
        }
    }
}
int main ()
{
    int i,n,a,b;
 
    scanf ("%d",&n);
    for (i=1;i<n;i++) {
        scanf ("%d %d",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    bfs1();
    bfs2(n);
    int m=n-cnt;
    if (m>cnt) printf ("Fennec\n");
    else printf("Snuke\n");
 
    return 0;
}