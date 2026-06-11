# include <cstdio>
# include <iostream>
# include <cstring>
# define R register int

using namespace std;

const int maxn=2003;
int n,k,x[maxn],y[maxn],firs[maxn],h,dep[maxn],t;
struct edge { int too,nex; }g[maxn<<1];

void add (int x,int y)
{
    g[++h].nex=firs[x];
    g[h].too=y;
    firs[x]=h;
}

void dfs (int x)
{
    if(dep[x]-1>(k/2)) t++;
    int j;
    for (R i=firs[x];i;i=g[i].nex)
    {
        j=g[i].too;
        if(dep[j]) continue;
        dep[j]=dep[x]+1;
        dfs(j);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for (R i=1;i<n;++i)
    {
        scanf("%d%d",&x[i],&y[i]);
        add(x[i],y[i]); add(y[i],x[i]);
    }
    int ans=n;
    if(k%2==0)
    {
        for (R i=1;i<=n;++i)
        {
            t=0;
            memset(dep,0,sizeof(dep));
            dep[i]=1;
            dfs(i);
            ans=min(ans,t);
        }
    }
    else
    {
        for (R i=1;i<n;++i)
        {
            t=0;
            memset(dep,0,sizeof(dep));
            dep[ x[i] ]=1;
            dep[ y[i] ]=1;
            dfs(x[i]);
            dfs(y[i]);
            ans=min(ans,t);
        }
    }
    printf("%d",ans);
    return 0;
}