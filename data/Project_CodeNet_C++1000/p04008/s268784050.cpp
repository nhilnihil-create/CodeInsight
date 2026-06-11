#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,k;
int ans=0;
int tot=0;
int h[100005],a[100005];
struct Edge
{
    int x,next;
}e[200005];
void add_edge(int x,int y)
{
    e[++tot].x=y;
    e[tot].next=h[x],h[x]=tot;
}
int dfs(int x,int deep)
{
    int ret=deep;
    for(int i=h[x];i;i=e[i].next)
    ret=max(ret,dfs(e[i].x,deep+1));
    if(a[x]!=1 && ret-deep==k-1)
	return ans++,0;
    else 
	return ret;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
    if(a[1]!=1)
	ans=a[1]=1;
    for(int i=2;i<=n;i++)
	add_edge(a[i],i);
    dfs(1,0);
	printf("%d\n",ans);
}