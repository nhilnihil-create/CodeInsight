#include <iostream>
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a;i<=n;i++)
#define per(i,a,n) for(int i = n;i>=a;i--)
#define Si(x) scanf("%d",&x)

#define pb push_back
/*
*
* Author : SIZ
*/
typedef long long ll;
const int maxn = 1e5+100;

using namespace std;

vector<int> Ve[maxn];

int col[maxn];
int cnt[4];

int main()
{
    int n,x,y;
    memset(cnt,0,sizeof(cnt));
    memset(col,0,sizeof(col));
    Si(n);

    rep(i,1,n-1)
    {
        Si(x),Si(y);
        Ve[x].pb(y);
        Ve[y].pb(x);
    }
    col[1] = 1; col[n] = 2;
    queue<int> Q;
    Q.push(1); Q.push(n);
    while(!Q.empty() )
    {
        int u = Q.front();
        Q.pop();
        cnt[ col[u] ]++;
        int len = Ve[u].size();
        for(int i = 0 ;i < len ; i++)
        {
            int vv = Ve[u][i];
            if( col[vv] != 0 ) continue;
            col[vv] = col[u];
            Q.push(vv);
        }
    }
    if( cnt[1] > cnt[2])
        printf("Fennec\n");
    else
        printf("Snuke\n");
    return 0;
}
