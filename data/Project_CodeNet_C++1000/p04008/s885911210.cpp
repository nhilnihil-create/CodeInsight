#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[233333],pool[233333];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int n,k,ans;
int a[233333],dep[233333],ok[233333];
void dfs1(int u)
{
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!dep[tmp->v])
		{
			dep[tmp->v]=dep[u]+1;
			dfs1(tmp->v);
		}
	}
}
void dfs2(int u)
{
	if(ok[u])return;
	ok[u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(dep[tmp->v]>dep[u])dfs2(tmp->v);
	}
}
pair<int,int> orz[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)addedge(a[i],i);
	}
	ans=(a[1]!=1);dep[1]=1;
	dfs1(1);
	for(int i=1;i<=n;i++)orz[i]=make_pair(dep[i],i);
	sort(orz+1,orz+n+1,greater<pair<int,int> >());
	for(int i=1;i<=n;i++)
	{
		int u=orz[i].second;
		if(!ok[u]&&dep[u]>k+1)
		{
			int qwq=u;
			for(int j=1;j<k;j++)qwq=a[qwq];
			ans++;
//			cerr<<"gao "<<qwq<<endl;
			dfs2(qwq);
		}
	}
	cout<<ans<<endl;
	return 0;
}