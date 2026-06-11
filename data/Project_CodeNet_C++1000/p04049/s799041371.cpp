#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2010,inf=1<<28;
struct data{
    int to,ne;
}a[N<<1];
int n,m,cnt=0,ans=0,maxx=0;
int h[N],d[N];
bool bo[N];
inline void add(int x,int y)
{
    a[++cnt].to=y;
    a[cnt].ne=h[x];
    h[x]=cnt;
    return;
}
inline void dfs1(int x,int fa,int y,int z)
{
    if(y>z) return;
    bo[x]=1,cnt++;
    for(int k=h[x];k;k=a[k].ne)
    {
        if(a[k].to==fa) continue;
        dfs1(a[k].to,x,y+1,z);
    }
    return;
}
inline void dfs2(int x,int fa)
{
    d[x]=0;
    for(int k=h[x];k;k=a[k].ne)
    {
        if(a[k].to==fa||bo[a[k].to]==0) continue;
        dfs2(a[k].to,x);
        maxx=max(maxx,d[a[k].to]+1+d[x]);
        d[x]=max(d[x],d[a[k].to]+1);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int k=1;k<n;k++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    if(m&1)
    {
        for(int k=1;k<=n;k++)
        {
            for(int i=h[k];i;i=a[i].ne)
            {
                if(a[i].to<k) continue;
                memset(bo,0,sizeof bo);
                cnt=maxx=0;
                dfs1(k,a[i].to,0,(m-1)/2);
                dfs1(a[i].to,k,0,(m-1)/2);
                dfs2(k,0);
                if(maxx<=m) ans=max(ans,cnt);
            }
        }
    }
    else
    {
        for(int k=1;k<=n;k++)
        {
            memset(bo,0,sizeof bo);
            cnt=maxx=0;
            dfs1(k,0,0,m/2);
            dfs2(k,0);
//            cout<<k<<" "<<cnt<<" "<<maxx<<endl;
            if(maxx<=m) ans=max(ans,cnt);
        }
    }
    printf("%d\n",n-ans);
    return 0;
}
