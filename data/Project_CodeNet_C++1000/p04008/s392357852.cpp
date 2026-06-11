#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,k,a[100010],dep[100010],maxn[100100],ans;
struct node{int y,nxt;
}g[100010];int h[100010];
void dfs(int x)
{
    for (int i=h[x];i;i=g[i].nxt)
    if (g[i].y!=x)
    {
        dep[g[i].y]=dep[x]+1;
        dfs(g[i].y);
        maxn[x]=max(maxn[x],maxn[g[i].y]);
    }
    maxn[x]=max(maxn[x],dep[x]);
    if (x==1) return;
    if (maxn[x]-dep[x]>=k-1&&a[x]!=1||(maxn[x]-dep[x]>=k)) maxn[x]=0,ans++;
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%d",&a[1]);
    for (int i=2;i<=n;i++) 
    {
        scanf("%d",&a[i]);    
        g[i]=node{i,h[a[i]]};h[a[i]]=i;    
    }
    ans=0;
    dfs(1);
    if (a[1]!=1) ans++;
    printf("%d",ans);
}