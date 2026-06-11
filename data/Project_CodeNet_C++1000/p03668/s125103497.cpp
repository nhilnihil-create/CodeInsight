#include<bits/stdc++.h>
using namespace std;

int N;
int dp[100010];
vector<int> V[100010];
int depth[100010] = {0};

int DP(int n)
{
    if(n == 1)
    {
        if(V[1].size() == 1)return DP(V[1][0]) + 1;
        int res = -1;
        for(int i = 0; i < V[1].size(); i++)
        {
            if(res == -1)res = DP(V[1][i]) + 1;
            else res ^= DP(V[1][i]) + 1;
        }
        return res;
    }
    if(V[n].size() == 1)return 0;
    if(V[n].size() == 2)
    {
        for(int i = 0; i < V[n].size(); i++)
        {
            if(depth[n] < depth[V[n][i]])return DP(V[n][i]) + 1;
        }
    }
    int res = -1;
    for(int i = 0; i < V[n].size(); i++)
    {
        if(depth[n] > depth[V[n][i]])continue;
        if(res == -1)res = DP(V[n][i]) + 1;
        else res ^= DP(V[n][i]) + 1;
    }
    return res;
}

void DFS(int n,int d)
{
    if(depth[n] != 0)return;
    depth[n] = d;
    for(int i = 0; i < V[n].size(); i++)
    {
        DFS(V[n][i],d + 1);
    }
}

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)dp[i] = -1;
    for(int i = 0; i < N - 1; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    DFS(1,1);
    if(DP(1))printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
