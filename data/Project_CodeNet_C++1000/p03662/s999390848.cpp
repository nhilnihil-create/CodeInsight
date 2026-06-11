#include <bits/stdc++.h>
using namespace std;
int n;
string ss="Snuke";
string ff="Fennec";
vector<int>g[100010];
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int>c(n+1);
	queue<int>q;
	q.push(1);q.push(n);
	c[1]=1;
	c[n]=2;
	int f=1,s=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<g[x].size();i++)
		{
			int y=g[x][i];
			if(c[y]==0)
			{
				q.push(y);
				c[y]=c[x];
				if(c[y]==1)f++;
				else s++;
			}
		}
	}
	if(f>s)cout<<ff;
	else cout<<ss;
	return 0;
}