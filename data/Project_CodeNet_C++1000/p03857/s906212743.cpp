#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long

const int MAX = 5e5+10;

vector<int>adj[MAX],adj1[MAX],comp[MAX];

int col[MAX] , col1[MAX];
bool vis[MAX] , vis1[MAX];
int cur = 1;
int cnt[MAX] , ans[MAX];

void DFS(int src)
{
    col[src] = cur;
    vis[src] = 1;
    comp[cur].push_back(src);

    for(int j=0;j<adj[src].size();j++)
    {
        int i = adj[src][j];
        if(!vis[i])
            DFS(i);
    }
}
void DFS1(int src)
{
    col1[src] = cur;
    vis1[src] = 1;

    for(int j=0;j<adj1[src].size();j++)
    {
        int i = adj1[src][j];
        if(!vis1[i])
            DFS1(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m1,m2;

    //memset(col,-1,sizeof col);
    //memset(col1,-1,sizeof col1);

    cin >> n >> m1 >> m2;

    int u,v;

    for(int i=0;i<m1;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<m2;i++)
    {
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    vector<int>compN;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            compN.push_back(cur);
            DFS(i);
            cur++;
        }
        if(!vis1[i])
        {
            DFS1(i);
            cur++;
        }
    }

    for(int z=0;z<compN.size();z++)
    {
        int i = compN[z];

        for(int j=0;j<comp[i].size();j++)
        {
            int x = comp[i][j];
            cnt[col1[x]]++;
        }
        for(int j=0;j<comp[i].size();j++)
        {
            int x = comp[i][j];
            ans[x] = cnt[col1[x]];
        }
        for(int j=0;j<comp[i].size();j++)
        {
            int x = comp[i][j];
            cnt[col1[x]]--;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(i > 1)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
