#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define inf 0x3f3f3f3f
typedef long long LL;
#define cls(x) memset(x,0,sizeof(x))
#define For(i,j,k) for(register int i=(j);i<=(k);++i)
#define Rep(i,j,k) for(register int i=(j);i>=(k);--i)
#define rint register int
#define il inline


const int N=2000+5;
int n,k,tot=1;
int head[N],ver[N<<1],nxt[N<<1],edge[N<<1];

il void add(int x,int y,int z)
{ ver[++tot]=y; nxt[tot]=head[x]; head[x]=tot; edge[tot]=z; }
int d[N][N];
int v[N];
void dfs(int x,int u)
{
    v[x]=u;
    for(rint i=head[x];i;i=nxt[i])
    {
        int y=ver[i]; if(v[y]==u) continue;
        d[u][y]=d[u][x]+edge[i];
        dfs(y,u);
    }
}

int ans=inf;
int main()
{
    scanf("%d %d",&n,&k);
    For(i,1,n-1) {int x,y; scanf("%d%d",&x,&y); add(x,y,1); add(y,x,1);}
    For(i,1,n) dfs(i,i);

    if(k&1)
    {
        for(rint i=2;i<=tot;i+=2)
        {
            int x=ver[i],y=ver[i^1]; int c=0;
            for(rint z=1;z<=n;++z)
                c+=(d[x][z]>k/2 && d[y][z]>k/2);
            ans=min(ans,c);
        }
    }
    else
    {
        for(rint x=1;x<=n;++x)
        {
            int c=0;
            for(rint y=1;y<=n;++y)
                c+=(d[x][y]>k/2);
            ans=min(ans,c);
        }
    }
    printf("%d\n",ans);
    return 0;
}