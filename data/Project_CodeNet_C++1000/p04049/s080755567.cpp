#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<iomanip>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2010;
int n,k,du[N],d1[N],head[N],z1;
struct node
{
    int u,v,nxt;
}e1[N*2];
void add_e1(int u,int v)
{
    z1++;
    e1[z1].u=u;e1[z1].v=v;
    e1[z1].nxt=head[u];
    head[u]=z1;
}
void dfs(int u,int fa,int d)
{
    d1[u]=d;
    for(int i=head[u];i;i=e1[i].nxt)
	{
        int v=e1[i].v;
        if(v==fa)continue;
        dfs(v,u,d+1);
    }
}
int main()
{ 
	int u,v;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
	{
       
        scanf("%d%d",&u,&v);
        add_e1(u,v);add_e1(v,u);
        du[u]++;du[v]++;
    }
    int ans=n;
    if(k&1)
        for(int u=1;u<=n;u++)
            for(int i=head[u];i;i=e1[i].nxt)
			{
                int v=e1[i].v;
                if(v<u)continue;
                dfs(u,v,0);
                dfs(v,u,0);
                int cnt=0;
                for(int j=1;j<=n;j++)
                    if(d1[j]>k/2)cnt++;
                ans=min(ans,cnt);
            }
    else
    for(int u=1;u<=n;u++)
	{
       dfs(u,0,0);
       int cnt=0;
       for(int j=1;j<=n;j++)
          if(d1[j]>k/2)
          cnt++;
    	ans=min(ans,cnt);
    }
    printf("%d\n",ans);
}