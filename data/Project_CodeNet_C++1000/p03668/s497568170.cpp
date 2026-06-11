#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;

vector<int>v[maxn];
int n;

int dfs(int x,int fa)
{
	int ans=0;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa)continue;
		ans^=(dfs(y,x)+1);
	}
	return ans;
}

int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(dfs(1,0))cout<<"Alice";
	else cout<<"Bob";
}