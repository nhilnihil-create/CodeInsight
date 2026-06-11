#include<bits/stdc++.h>
using namespace std;
int fa[500000];
int fb[500000];
int finda(int x)
{
    return x==fa[x]?x:fa[x]=finda(fa[x]);
}
int findb(int x)
{
    return x==fb[x]?x:fb[x]=findb(fb[x]);
}
int main()
{
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        fb[i]=i;
    }
    for(int i=1;i<=k;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int fu=finda(u);
        int fv=finda(v);
        if(fu!=fv)
        {
            fa[fu]=fv;
        }
    }
    for(int i=1;i<=l;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int fu=findb(u);
        int fv=findb(v);
        if(fu!=fv)
        {
            fb[fu]=fv;
        }
    }
    for(int i=1;i<=n;i++)
    {
        finda(i);
        findb(i);
    }
    map<pair<int,int>,int>mmp;
    for(int i=1;i<=n;i++)
    {
        mmp[make_pair(fa[i],fb[i])]++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ", mmp[make_pair(fa[i],fb[i])]);
    }
    printf("\n");
}
