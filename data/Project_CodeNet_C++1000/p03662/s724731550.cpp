# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x,y;
	queue <int> q;
	vector <int> v[100005];
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		v[y].push_back(x);
		v[x].push_back(y);
	}
	q.push(0);
	q.push(n-1);
	int color[n+10];
	memset(color,-1,sizeof color);
	color[n-1]=1;
	color[0]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int j=0;j<v[u].size();j++)
		{
			if(color[v[u][j]]==-1)
			{
				color[v[u][j]]=color[u];
				q.push(v[u][j]);
			}
		}
	}
	int black=0,white=0;
	for(int i=0;i<n;i++)
	{
		if(color[i]==0)
		black++;
		else
		white++;
	}
	if(black>white)
	cout<<"Fennec";
	else
	cout<<"Snuke";
	return 0;
}