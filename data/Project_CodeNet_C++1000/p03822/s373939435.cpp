#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int>G[1<<17];
int dfs(int u)
{
	if(G[u].empty())return 0;
	vector<int>a;
	for(int i=0;i<G[u].size();i++)
	{
		a.push_back(dfs(G[u][i]));
	}
	sort(a.begin(),a.end());
	int g=a[a.size()-1];
	int c=0;
	for(int i=a.size()-1;i--;)
	{
		if(a[i+1]>a[i])c+=a[i+1]-a[i]-1;
		else
		{
			if(c)c--;
			else g++;
		}
	}
	return g+1;
}
main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a;cin>>a;
		G[a].push_back(i+1);
	}
	cout<<dfs(1)<<endl;
}