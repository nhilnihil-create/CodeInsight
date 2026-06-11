#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct edges
{
	int to,next;
}edge[101010];
int first[101010],now;
void adde(int x,int y)
{
	now++;
	edge[now].to=y;
	edge[now].next=first[x];
	first[x]=now;
}
int a[101010];
int h[101010];
int dfn[101010],dd;
void dfs(int p)
{
	dfn[++dd]=p;
	for(int e=first[p];e;e=edge[e].next)
		dfs(edge[e].to);
}
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(first,0,sizeof(first));
	now=0;
	if(a[1]!=1)
		ans++;
	for(int i=2;i<=n;i++)
		adde(a[i],i);
	dd=0;
	dfs(1);
	memset(h,0,sizeof(h));
	for(int i=1;i<=n;i++)
		h[i]=1;
	for(int i=dd;i>1;i--)
	{
		if(h[dfn[i]]==k&&a[dfn[i]]!=1)
			ans++;
		else
			h[a[dfn[i]]]=max(h[a[dfn[i]]],h[dfn[i]]+1);
	}
	printf("%d",ans);
	return 0;
}