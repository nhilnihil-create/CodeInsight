#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> v[100011];
int d[2][100011],id=0;
void dfs(int idx,int par=-1)
{
	if(~par)//if(par!=-1)
	d[id][idx]=d[id][par]+1;
	for(int i=0;i<v[idx].size();i++)//for(auto &to:g[idx])
	if(v[idx][i]!=par)//if(to!=par)
	dfs(v[idx][i],idx);//dfs(to,idx);
}
int main()
{
	cin >>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin >>a>>b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	id=0;
	dfs(0);
	id=1;
	dfs(n-1);
	int ans=0;
	for(int i=0;i<n;i++)
	if(d[0][i]<=d[1][i])
	ans++;
	if(ans>=n/2+1)
	puts("Fennec");
	else
	puts("Snuke");
	return 0;
}