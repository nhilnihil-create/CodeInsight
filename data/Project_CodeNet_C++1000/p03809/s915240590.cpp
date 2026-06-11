#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int N;
ll A[100010];
ll U[100010];
int par[100010];
vector<pii> mem;
vector<int> G[100010];
bool visit[100010] = {0},F = false;
int root;

void DFS(int v,int p,int d)
{
    if(visit[v])return;
    visit[v] = true;
    par[v] = p;
    mem.push_back(make_pair(d,v));
    for(int i = 0; i < G[v].size(); i++)if(G[v][i] != p)DFS(G[v][i],v,d + 1);
    return;
}

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%lld",A + i + 1);

    for(int i = 0; i < N - 1; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(N == 2)
    {
        if(A[1] == A[2])printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    for(int i = 1; i <= N; i++)
    {
        if(G[i].size() > 1)
        {
            root = i;
            DFS(i,-1,0);
            break;
        }
    }
    sort(mem.begin(),mem.end());
    reverse(mem.begin(),mem.end());
    for(int i = 0; i < N; i++)
    {
        int v = mem[i].second;
        if(G[v].size() == 1)
        {
            U[v] = A[v];
            continue;
        }
        ll sum = 0,MAX = 0,MIN = 100000000000;
        for(int i = 0; i < G[v].size(); i++)
        {
            if(par[v] == G[v][i])continue;
            sum += U[G[v][i]];
            MAX = max(MAX,U[G[v][i]]);
            if(U[G[v][i]] == -1 || A[v] < U[G[v][i]])F = true;
        }
        if(A[v] * 2 < sum || A[v] < A[v] * 2 - sum)U[v] = -1;
        else U[v] = A[v] * 2 - sum;
    }
    if(U[root] == 0 && !F)printf("YES\n");
    else printf("NO\n");
    return 0;
}
