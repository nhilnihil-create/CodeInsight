#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt;
long long up[101010],siz[101010],a[101010];
int nxt[202020],to[202020],fir[101010];
char S[3][10]={"NO","YES"};
void add(int x,int y)
{
	nxt[++cnt]=fir[x];fir[x]=cnt;
	to[cnt]=y;
}
int dfs(int x,int f)
{
	siz[x]=up[x]=0;
	int c=0;
	for(int i=fir[x];i;i=nxt[i])
	if(to[i]!=f)
	{
		c++;
		int di=dfs(to[i],x);
		if(!di) return 0;
		long long k=up[to[i]];
		long long f2=min(k,up[x]);
		k-=f2;up[x]-=f2;
		long long fl=min(siz[x],k/2);
		k-=fl*2;siz[x]+=fl+f2;
		up[x]+=k;
	}
	if(c==0) { up[x]=a[x]; return 1; }
	if(x==1)
	{
		if(c==1) return up[x]==a[x];
		else return up[x]==0&&siz[x]==a[x];
	}
	else if(up[x]+siz[x]>a[x]) return 0;
	else if(up[x]+siz[x]<=a[x])
	{
		long long k=a[x]-up[x]-siz[x];
		if(siz[x]<k) return 0;
		siz[x]-=k;up[x]+=k*2;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	printf("%s\n",S[dfs(1,0)]);
	return 0;
}