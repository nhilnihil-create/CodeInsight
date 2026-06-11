#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long 
const int maxn = 1e5+10;
vector <int> vec[maxn];
int n,m;
int vis[maxn];
int ans[2],sta[2][maxn];
void dfs(int u,int cur)
{
	vis[u]=1;
	ans[cur]++;
	sta[cur][ans[cur]]=u;
	for(auto v:vec[u])
	{
		if(vis[v]) continue;
		dfs(v,cur);
		break;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	int st;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	    st=u;
	}
	vis[st]=1;
	dfs(vec[st][0],0);
	for(int i=1;i<vec[st].size();i++)
	{
		int v=vec[st][i];
		if(vis[v]) continue;
		dfs(v,1);
		break;
	}
	printf("%d\n",ans[0]+ans[1]+1);
	for(int i=ans[0];i;i--) printf("%d ",sta[0][i]);
	printf("%d ",st);
	for(int i=1;i<=ans[1];i++) printf("%d ",sta[1][i]);
	return 0;
}