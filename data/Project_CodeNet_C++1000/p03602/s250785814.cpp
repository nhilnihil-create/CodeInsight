#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,dis[410][410],a[410][410],tot;
LL sum;
struct Edge
{
    int f,t,w;
    friend bool operator<(const Edge &p,const Edge &q)
    {
        return p.w>q.w;
    }
}e[100010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&dis[i][j]);
            a[i][j]=dis[i][j];
            if(i<j) ++tot,e[tot].f=i,e[tot].t=j,e[tot].w=dis[i][j],sum+=dis[i][j];
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]!=dis[i][j]) {puts("-1");return 0;}
    sort(e+1,e+tot+1);
    for(int i=1;i<=tot;i++)
    {
        int x=e[i].f,y=e[i].t;
        int a=0,b=0,c=0;
        for(int k=1;k<=n;k++)
            if(k!=x&&k!=y)
            {
                if(dis[x][k]+dis[k][y]<dis[x][y]) a++;
                else if(dis[x][k]+dis[k][y]==dis[x][y]) b++;
                else c++;
            }
        if(a+b>0) sum-=e[i].w;
    }
    printf("%lld\n",sum);
    return 0;
}
