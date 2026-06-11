#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
int n,i,j,k,a[N],head[N],adj[N*2],nxt[N*2],d[N];
ll w[N];
bool dfs(int x,int dad)
{
	if(!nxt[head[x]])
	{
		w[x]=a[x];
		return true;
	}
	long long s=0,mx=0;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			if(!dfs(adj[y],x))
				return false;
			s+=w[adj[y]];
			mx=max(mx,w[adj[y]]);
		}
	ll B=s-a[x],A=2*a[x]-s;
	if(B<0||A<0||(mx>s/2&&B>s-mx))
		return false;
	w[x]=A;
	return true;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	if(n==2)
	{
		if(a[1]==a[2])
			printf("YES");
		else
			printf("NO");
		return 0;
	}
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		++d[j],++d[k];
	}
	for(i=1;i<=n;++i)
		if(d[i]!=1)
			break;
	if(!dfs(i,-1)||w[i])
		printf("NO");
	else
		printf("YES");
	return 0;
}
