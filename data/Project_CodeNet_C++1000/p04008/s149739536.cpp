#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <set>
const int maxlongint=2147483647;
const int mo=1e9+7; 
const int N=100005;
using namespace std;
int n,m,ans,deep[N],a[N];
int tot,nt[N*2],lt[N*2],to[N*2];
bool bz[N];
void link(int x,int y)
{
    nt[++tot]=lt[x];
    lt[x]=tot;
    to[tot]=y;
}
int dg(int x,int fa)
{
    deep[x]=deep[fa]+1;
    int mx=deep[x];
    for(int i=lt[x];i;i=nt[i]) mx=max(dg(to[i],x),mx);
    if(x==1) return 0;
    if(fa!=1 && mx-deep[x]+1==m) ans++,mx=0;
    return mx;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i!=1) link(a[i],i);
    }
    if(a[1]!=1) ans++;
    deep[0]=-1;
    dg(1,0);
    printf("%d",ans);
}