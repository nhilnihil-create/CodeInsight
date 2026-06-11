#include<iostream>
#include<vector>
using namespace std;

int n,m,q;
vector<int> e[100005];
int v[100005],d[100005],c[100005];
int color[100005],dist[100005];

void dfs(int u,int d,int col)
{
    if(d<=dist[u]) return;
    dist[u]=d;
    if(color[u]==-1) color[u]=col;
    for(int i=0;i<e[u].size();i++)
        dfs(e[u][i],d-1,col);
}

int main()
{

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>v[i]>>d[i]>>c[i];
        v[i]--;
    }
    fill(dist,dist+100005,-1);
    fill(color,color+100005,-1);
    
    for(int i=q-1;i>=0;i--)
        dfs(v[i],d[i],c[i]);
    for(int i=0;i<n;i++)
        cout<<((color[i]==-1)?0:color[i])<<'\n';

    return 0;
}