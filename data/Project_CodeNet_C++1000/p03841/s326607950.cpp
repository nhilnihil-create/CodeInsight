#include <bits/stdc++.h>
using namespace std;
pair<int,int> x[505];
int ans[250005],c[505];
int main()
{
	int n,cur=1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x[i].first);
		x[i].second=i;
		ans[x[i].first]=i;
	}
	sort(x+1,x+n+1);
	for (int i=1;i<=n;i++)
	{
		int cnt=x[i].second-1;
		while (cnt--)
		{
			while (ans[cur])
			cur++;
			ans[cur]=x[i].second;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int cnt=n-x[i].second;
		while (cnt--)
		{
			while (ans[cur])
			cur++;
			ans[cur]=x[i].second;
		}
	}
	for (int i=1;i<=n*n;i++)
	{
		c[ans[i]]++;
		if (c[ans[i]]==ans[i])
		{
			for (int j=1;j<=n;j++)
			{
				if (x[j].second==ans[i] && x[j].first!=i)
				{
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
	for (int i=1;i<=n*n;i++)
	printf("%d ",ans[i]);
}