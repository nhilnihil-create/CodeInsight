#include <iostream>
using namespace std;
typedef long long ll;
int n,k;
const int MAXN=2005;
struct Edge
{
	int u,v,next;
}e[MAXN*2];
int h[MAXN],cnt,size[MAXN];
void addEdge(int u,int v)
{
	e[++cnt].v=v;e[cnt].next=h[u];h[u]=cnt,e[cnt].u=u;
	e[++cnt].v=u;e[cnt].next=h[v];h[v]=cnt,e[cnt].u=v;
}
int dfs(int u,int anc,int dep)
{
	int tmp=1;
	if(dep==k/2)
		return 1;
	else
		for(int i=h[u];i;i=e[i].next)
			if(e[i].v!=anc)tmp+=dfs(e[i].v,u,dep+1);
	return tmp;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		addEdge(x,y);
		size[x]++;
		size[y]++;
	}
	int ans=0;
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
			ans=max(ans,dfs(i,0,0));
	}
	else
	{
		for(int i=1;i<=cnt;i+=2)
			ans=max(ans,dfs(e[i].u,e[i].v,0)+dfs(e[i].v,e[i].u,0));
	}
	cout<<n-ans<<endl;
	return 0;
}