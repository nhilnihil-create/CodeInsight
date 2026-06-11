#include<bits/stdc++.h>
#define N 400005
#define ll long long
using namespace std;
int n,m;
int head[N],ver[N],nxt[N],tot;
void add(int a,int b)
{
    tot++;nxt[tot]=head[a];head[a]=tot;ver[tot]=b;return ;
}
int v[N];
int cnt,flag,sz,szz,tp;
void dfs(int x,int c)
{
    cnt++;v[x]=c;
    for(int i=head[x];i;i=nxt[i])
    {
        if(v[ver[i]]==-1)dfs(ver[i],c^1);
        else if(v[ver[i]]!=(c^1))flag=1;
    }
    return ;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        add(t1,t2);add(t2,t1);
    }
    ll ans=0;memset(v,-1,sizeof(v));
    for(int i=1;i<=n;i++)
    {
         cnt=0;flag=0;
         if(v[i]==-1)dfs(i,0);
         if(cnt)
         {
             if(flag||cnt==1)ans++;
             else ans+=2;
             if(cnt==1)tp++;
             else
             {
                 if(!flag)szz++;
                 else sz++;
             }
         }
    }
   //cout<<tp<<" "<<sz<<" "<<szz<<endl;
    ans=1ll*tp*n+1ll*tp*(n-tp)+1ll*sz*szz*2+1ll*sz*sz+2ll*szz*szz;
    cout<<ans<<endl;
    return 0;
}