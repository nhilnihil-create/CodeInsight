#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100005];

int DFS(int u,int root)
{
    int rs=0;
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]!=root)
            rs^=DFS(g[u][i],u)+1;
    return rs;
}

int main()
{
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(DFS(1,-1)>0)
        cout<<"Alice";
    else
        cout<<"Bob";
}
