#include <bits/stdc++.h>
using namespace std;
vector <int> m;
int fir,n;
int cnt[100011];
vector <int> v[100011];
void dfs(int now,int par)
{
	cnt[now]=1;
	m.push_back(now);
	if(n-1==now)
	fir=m[(m.size()+1)/2];
	for(int i=0;i<v[now].size();i++)
	{
		if(v[now][i]==par)
		continue;
		dfs(v[now][i],now);
		cnt[now]+=cnt[v[now][i]];
	}
	m.pop_back();
}
int main()
{
	cin >>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin >>x>>y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(0,0);
	puts((cnt[fir]*2<n)?"Fennec":"Snuke");
	return 0;
}