#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

typedef long long LL;

int N, M;
int bp, nbp, one, sz;
bool bip;
vector <int> edg[100005];
bitset <100005> vis;
int par[100005];

void DFS(int nod, int pr)
{
    if(vis[nod])
    {
        if(pr != par[nod])  bip = 0;
        return;
    }

    vis[nod] = 1;
    sz++;
    par[nod] = pr;
    for(auto nxt: edg[nod])
        DFS(nxt, pr ^ 1);
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    for(int i = 1; i <= N; i++)
        if(!vis[i])
        {
            sz = 0;
            bip = 1;
            DFS(i, 0);

            if(sz == 1)     one++;
            else if(bip)    bp++;
            else            nbp++;
        }

    LL ansone = 1LL * one * one + 2LL * one * (N - one);
    LL ansbip = 2LL * bp * bp + 1LL * nbp * nbp + 2LL * bp * nbp;
    LL ans = ansone + ansbip;
    printf("%lld\n", ans);

    return 0;
}
