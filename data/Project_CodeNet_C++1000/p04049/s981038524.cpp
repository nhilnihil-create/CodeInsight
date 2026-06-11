#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2000;

int n, k, deg[MAXN+10], ans;
vector<int> adj[MAXN+10];

int cnt, chd, add;
void dfs(int now, int par, int dep)
{
    cnt++;
    if(dep==k/2)
    {
        chd+=deg[now]-1;
        return;
    }
    for(int nxt : adj[now])
    {
        if(nxt==par) continue;
        dfs(nxt, now, dep+1);
    }
}

int main()
{
    int i, j;

    scanf("%d%d", &n, &k);
    if(k==1) return !printf("%d", n-2);
    for(i=1; i<n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v); deg[u]++;
        adj[v].push_back(u); deg[v]++;
    }

    for(i=1; i<=n; i++)
    {
        cnt=1, add=0;
        for(int nxt : adj[i])
        {
            chd=0;
            dfs(nxt, i, 1);
            add=max(add, chd);
        }
        if(k%2) cnt+=add;
        ans=max(ans, cnt);
    }
    printf("%d", n-ans);
}
