#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100010];
int n,m,k;
int a[100010],b[100010],c[100010];
int d[100010];
int r[100010]={0};
void dfs(int x,int y,int col)
{
	//cout <<x<<" "<<y<<" "<<col<<" "<<d[x]<<"\n{\n";
	if (y<=d[x]) return;
	else d[x]=y;
	if (!r[x]) r[x]=col;
	if (!y) return;
	else
	{
		for (int i=0;i<v[x].size();i++)
		{
			int xi=v[x][i];
			dfs(xi,y-1,col);
		}
		//cout <<"}\n";
	}
}
int main()
{
	cin >>n>>m;
	for (int i=0;i<m;i++)
	{
		int x,y;
		cin >>x>>y;
		x--,y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >>k;
	for (int i=0;i<k;i++) cin >>a[i]>>b[i]>>c[i],a[i]--;
	fill(d,d+n,-1);
	for (int i=k-1;i>=0;i--) dfs(a[i],b[i],c[i]);
	for (int i=0;i<n;i++) cout <<r[i]<<"\n";
	return 0;
} 