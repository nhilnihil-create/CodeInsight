#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int n,k,ans;
int dfs(int node,int dep)
{
	int mx=1;
	for (int u:v[node])
	mx=max(mx,dfs(u,dep+1)+1);
	if (mx==k && dep>1)
	{
		ans++;
		mx=0;
	}
	return mx;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if (i==1)
		ans+=(a!=1);
		else
		v[a].push_back(i);
	}
	dfs(1,0);
	printf("%d",ans);
}