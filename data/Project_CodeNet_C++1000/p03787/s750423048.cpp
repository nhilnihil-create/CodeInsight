#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 100010;
vector<int> e[N];
int vis[N],col[N],tag,n,m;
ll point,bi,con,cnt,ans,tot;
int dfs(int p,int c)
{
    cnt++;
    vis[p] = 1;
    col[p] = c;
    for (int i = 0;i < e[p].size();i++)
    {
        int x = e[p][i];
        if (!vis[x]) dfs(x,c^1);
        else {
            if (col[p] == col[x]) tag = 1;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0;i < m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    for (int i = 1;i <= n;i++)
    {
        cnt = tag = 0;
        if (!vis[i])
        {
            dfs(i,0);
            if (cnt == 1)
            {
                ans = ans + tot*2 + 1;
                point++;
            } else if (tag == 1)
            {
                ans = ans + (cnt*point+bi+con)*2 + 1;
                con++;
            } else {
                ans = ans + (cnt*point+2*bi+con)*2 + 2;
                bi++;
            }
            tot += cnt;
        }
    }
    printf("%lld",ans);
    return 0;
}
