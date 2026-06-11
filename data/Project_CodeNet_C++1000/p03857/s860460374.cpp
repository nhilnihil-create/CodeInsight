#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,m2,i,j,fa[200005][2],x,y;
map<pair<int,int>,int> mp;
int find(int x,int y)
{
	if (fa[x][y]==x) return x;
	return fa[x][y]=find(fa[x][y],y);
}
int main()
{
	cin>>n>>m>>m2;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=1;j++) fa[i][j]=i;
	}
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		if (find(x,0)!=find(y,0))
		{
			fa[find(x,0)][0]=find(y,0);
		}
	}
	for (i=1;i<=m2;i++)
	{
		cin>>x>>y;
		if (find(x,1)!=find(y,1))
		{
			fa[find(x,1)][1]=find(y,1);
		}
	}
	for (i=1;i<=n;i++)
	{
		find(i,0);find(i,1);
		mp[make_pair(fa[i][0],fa[i][1])]++;
	}
	for (i=1;i<=n;i++)
	{
		cout<<mp[make_pair(fa[i][0],fa[i][1])]<<' ';
	}
	return 0;
}