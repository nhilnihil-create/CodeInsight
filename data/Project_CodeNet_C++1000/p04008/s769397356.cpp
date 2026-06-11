#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define N 101000
using namespace std;
int ans=0,n,k,a[N],nxt[N],last[N],to[N],deep[N],tot=0;
void putin(int x,int y)
{
	if(y==1) return;
	nxt[++tot]=last[x];last[x]=tot;to[tot]=y;
}
void dg(int x)
{
	deep[x]=1;
	for(int i=last[x];i;i=nxt[i])
	{
		int y=to[i];
		dg(y);deep[x]=max(deep[x],deep[y]+1);
	}
	if(deep[x]>=k&&a[x]!=1)
	{
		deep[x]=0;ans++;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	fo(i,1,n) scanf("%d",&a[i]),putin(a[i],i);
	if(a[1]!=1) a[1]=1,ans=1;
	dg(1);
	printf("%d\n",ans);
}