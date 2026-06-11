#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n;
int a[N],du[N];
int head[N],ver[N],nxt[N],tot;
void add(int a,int b)
{
    tot++;nxt[tot]=head[a];head[a]=tot;ver[tot]=b;return ;
}
int f[N];
void dfs(int x,int fa)
{
    int sum=0,mx=0;
    bool flag=0;
    for(int i=head[x];i;i=nxt[i])
    {
        if(ver[i]==fa)continue;
        flag=1;
        dfs(ver[i],x);
        sum+=f[ver[i]];mx=max(mx,f[ver[i]]);
    }
    if(!flag){f[x]=a[x];return ;}
    int mn;
    if(mx<=(sum+1)/2)mn=sum/2+sum%2;
    else mn=mx;
    if(a[x]>sum||a[x]<mn)
    {
        puts("NO");
        exit(0);
    }
    f[x]=2*a[x]-sum;
}
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int t1,t2;
    for(int i=1;i<n;i++)
    {
        scanf("%lld%lld",&t1,&t2);
        add(t1,t2);add(t2,t1);
        du[t1]++;du[t2]++;
    }
    if(n==2)
    {
        if(a[1]==a[2])puts("YES");
        else puts("NO");
        return 0;
    }
    int root;
    for(int i=1;i<=n;i++)if(du[i]>=2)root=i;
    dfs(root,-1);
    if(f[root]!=0)puts("NO");
    else puts("YES");
    return 0;
}
