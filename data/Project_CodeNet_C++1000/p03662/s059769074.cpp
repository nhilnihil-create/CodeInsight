#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
int n;
vector<int> edge[100010];
int a[100010];
int main()
{
	cin >>n;
	for (int i=0;i<n-1;i++)
	{
		int x,y;
		cin >>x>>y;
		x--,y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	fill(a,a+n,-1);
	a[0]=1;
	a[n-1]=0;
	q.push(0);
	q.push(n-1);
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		int col=a[x];
		for (int i=0;i<edge[x].size();i++)
		{
			if (a[edge[x][i]]==-1)
			{
				a[edge[x][i]]=col;
				q.push(edge[x][i]);
			}
		}
	}
	int f=0,s=0;
	for (int i=0;i<n;i++)
	{
		if (a[i]) f++;
		else s++;
	}
	cout <<(f>s ? "Fennec" : "Snuke");
	return 0;
}