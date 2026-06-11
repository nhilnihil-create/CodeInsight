#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 100005
int n,t[MAXN];
vector<int> G[MAXN];
void dfs(int u,int f)
{
	map<int,int> cnt;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==f) continue;
		dfs(v,u);
		cnt[t[v]]++;
	}
	map<int,int>::iterator it;
	for(it=cnt.begin();it!=cnt.end();it++)
	{
		if(it->second>1)
			cnt[(it->first)+1]+=it->second-1;
	}
	//父亲每个时刻只能找一个儿子打 剩下的儿子要推到后面
	if(it!=cnt.begin())//表示有儿子，进去过循环
		it--,t[u]=it->first+1;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		G[i].push_back(x);
		G[x].push_back(i);
	}
	dfs(1,0);
	printf("%d\n",t[1]);
}