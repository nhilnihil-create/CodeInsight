#include<bits/stdc++.h>
#define mxn 100005
using namespace std;
vector<int>adj[mxn];
int dfs(int x, int p)
{
    int xr= 0;
    for(int i=0; i<adj[x].size(); i++)
    {
        int y= adj[x][i];
        if(y!=p)xr^= (1+dfs(y, x));
    }
    return xr;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(dfs(1, 1))puts("Alice");
    else puts("Bob");
    return 0;
}
