#include<cstdio>
#define neko 100010
#define f(i,a,b) for(register int i=(a);i<=(b);i=-(~(i)))
#define travel(i,u,v) for(register int i=head[u],v=e[i].v;i;i=e[i].nex,v=e[i].v)
int ans,n,K,t;
typedef int arr[neko];
arr head;
struct node
{int v,nex;}e[neko<<1];
int cmax(int a,int b){return a>b?a:b;}
void add(int x,int y)
{
	e[++t].v=y,e[t].nex=head[x],head[x]=t;
	e[++t].v=x,e[t].nex=head[y],head[y]=t;
}
int dfs(int u,int fa,int dep)
{
	int now=dep,flag=0;
	travel(i,u,v)if(v^fa)now=cmax(dfs(v,u,dep+1),now);
	if(u==1)return 0;
	if((now-dep+1)==K&&fa^1)++ans,flag=1;
	return flag?dep-1:now;
}
int main()
{
	int x;
	scanf("%d%d",&n,&K);
	scanf("%d",&x);if(x^1)++ans;
	f(i,2,n)scanf("%d",&x),add(x,i);
	dfs(1,0,0);
	printf("%d\n",ans);

}