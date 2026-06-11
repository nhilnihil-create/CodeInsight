#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
int n;
vector<int> edge[100010];
int a[100010];
int b[100010];
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
	fill(b,b+n,-1);
	q.push(0);
	a[0]=0;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		int t=a[x];
		for (int i=0;i<edge[x].size();i++)
		{
			int xi=edge[x][i];
			if (a[xi]==-1)
			{
				q.push(xi);
				a[xi]=t+1;
			}
		}
	}
	q.push(n-1);
	b[n-1]=0;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		int t=b[x];
		for (int i=0;i<edge[x].size();i++)
		{
			int xi=edge[x][i];
			if (b[xi]==-1)
			{
				q.push(xi);
				b[xi]=t+1;
			}
		}
	}
	int r1=0,r2=0;
	for (int i=0;i<n;i++)
	{
		if (a[i]<=b[i]) r1++;
		else r2++;
	}
	cout <<(r1>r2 ? "Fennec" : "Snuke");
	return 0;
}