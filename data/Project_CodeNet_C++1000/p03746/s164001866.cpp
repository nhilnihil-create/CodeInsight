#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> v[100005];
deque<int> ans;
bool vis[100005];
void dfs(int node,int pos)
{
	for (int u:v[node])
	{
		if (!vis[u])
		{
			if (pos)
			ans.push_back(u);
			else
			ans.push_front(u);
			vis[u]=1;
			dfs(u,pos);
			break;
		}
	}
}
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vis[a]=1;
	vis[b]=1;
	ans.push_back(a);
	ans.push_back(b);
	dfs(a,0);
	dfs(b,1);
	printf("%d\n",ans.size());
	for (int i:ans)
	printf("%d ",i);
}