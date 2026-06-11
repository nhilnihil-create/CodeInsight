#include<bits/stdc++.h>
using namespace std;
int hea[100010],nxt[200010],to[200010],d[100010],tot;
long long v[100010];
void fason(int x,int y)
{
	nxt[++tot]=hea[x];
	hea[x]=tot;
	to[tot]=y;
}
long long dfs(int x,int f,int fa)
{
	if(d[x]==1)return v[x];
	long long s=0;
	for(int i=hea[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa)continue;
		long long t=dfs(y,0,x);
		if(t==-1||t>v[x])return -1;
		s+=t;
	}
	if(f==1)return s==v[x]*2?1:-1;
	if(s>2*v[x]||v[x]-s>0)return -1;
	else return 2*v[x]-s;
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",v+i);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		fason(x,y);
		fason(y,x);
		d[x]++;
		d[y]++;
	}
	if(n==2)
	{
		puts(v[1]==v[2]?"YES":"NO");
		return 0;
	}
	int rt;
	for(int i=1;i<=n;i++)
		if(d[i]>1)
		{
			rt=i;
			break;
		}
	if(dfs(rt,1,0)==1)puts("YES");
	else puts("NO");
	return 0;
}