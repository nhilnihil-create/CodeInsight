#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,i,vis[100005],x,y,seq[100005],cnt=0,pre;
vector<int> s[100005];
void dfs1(int p)
{
	int i,v;
	seq[++cnt]=p;
	vis[p]=1;
	for(i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(vis[v])continue;
		dfs1(v);
		break;
	}
}
void dfs2(int p)
{
	int i,v;
	for(i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(vis[v])continue;
		vis[v]=1;
		dfs2(v);
		seq[++cnt]=v;
		break;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)	
	{
		scanf("%d%d",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
	}
	dfs1(1);
	pre=cnt;
	dfs2(1);
	printf("%d\n",cnt);
	for(i=pre+1;i<=cnt;i++)printf("%d ",seq[i]);
	for(i=1;i<=pre;i++)printf("%d ",seq[i]); 
	return 0;
} 