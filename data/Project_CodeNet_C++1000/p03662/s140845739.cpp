#include <iostream>
#include <vector>
using namespace std;
const int SHN=100010;
int n;
bool visit[SHN]={0};
int a[SHN];
int b[SHN];
vector<int> edge[SHN];
int bl=0;
int wh=0;
inline void dfs(int x,int t,bool col)
{
	visit[x]=1;
	if (!col) a[x]=t;
	else b[x]=t;
	for (int i=0;i<edge[x].size();i++)
	{
		if (!visit[edge[x][i]]) dfs(edge[x][i],t+1,col);
	}
}
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
	dfs(0,0,0);
	fill(visit,visit+n,0);
	dfs(n-1,0,1);
	for (int i=0;i<n;i++)
	{
		int x=a[i];
		int y=b[i];
		if (x<=y) bl++;
		else wh++;
	}
	if (wh>=bl) cout <<"Snuke";
	else cout <<"Fennec";
	return 0;
}