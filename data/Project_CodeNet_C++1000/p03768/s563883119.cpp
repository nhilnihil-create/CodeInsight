#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
int n,m,a[N];
vector<int> e[N];
int vis[N];
int f[N][15];
struct node{
	int v,d,c;
}q[N];
void fun(int u,int d,int c)
{
	if(f[u][d]!=-1)
		return;
	if(!a[u])//已经被编号大的上过色 
	a[u]=c;
	if(d==0)//边界 
		return;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		fun(v,d-1,c);
	}
	f[u][d]=1;
}
int main()
{
	while(cin>>n>>m)
	{
		int u,v;
		for(int i=1;i<=n;i++)
			e[i].clear();
		memset(a,0,sizeof(a));
		memset(f,-1,sizeof(f));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int Q;
		cin>>Q;
		for(int i=0;i<Q;i++)
			scanf("%d%d%d",&q[i].v,&q[i].d,&q[i].c);
		for(int i=Q-1;i>=0;i--)
		{
			fun(q[i].v,q[i].d,q[i].c);
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<endl;
	}
	return 0;
}