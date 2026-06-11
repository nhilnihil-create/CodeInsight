#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int dfs(int node)
{
	vector<int> c;
	for (int u:v[node])
	c.push_back(dfs(u));
	sort(c.begin(),c.end(),greater<int>());
	int ret=0;
	for (int i=0;i<c.size();i++)
	ret=max(ret,c[i]+i+1);
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	printf("%d",dfs(1));
}