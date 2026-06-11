#include <iostream>
#include <queue>
#include <vector>
#define SHN 1000000ll
using namespace std;
int n;
vector<int> d1(100010,SHN),d2(100010,SHN);
vector<int> edge[100010];
void bfs(vector<int> &d,int s)
{
	queue<int> q;
	q.push(s);
	d[s]=0;
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		int t=d[x];
		for (int i=0;i<edge[x].size();i++)
		{
			int xi=edge[x][i];
			if (d[xi]>t+1) d[xi]=t+1,q.push(xi);
		}
	}
}
int main()
{
	cin >>n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >>x>>y;
		x--,y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	bfs(d1,0);
	bfs(d2,n-1);
	int r1=0,r2=0;
	for (int i=0;i<n;i++)
	{
		//cout <<d1[i]<<" "<<d2[i]<<"\n";
		if (d1[i]<=d2[i]) r1++;
		else r2++;
	}
	cout <<(r1>r2 ? "Fennec" : "Snuke");
	return 0;
}