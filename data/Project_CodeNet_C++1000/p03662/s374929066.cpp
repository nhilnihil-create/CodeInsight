#include<bits/stdc++.h>
using namespace std;
int color[100050],fath[100050],n,ans[2];
vector <int> V[100050];
void build(int now,int f)
{
	fath[now]=f;
	for(int i=0;i<V[now].size();i++)
		if(V[now][i]!=f)build(V[now][i],now);
	return;
}
void dfs(bool flag,int now)
{
	color[now]=flag;
	ans[flag]++;
	for(int i=0;i<V[now].size();i++)
		if(color[V[now][i]]==-1)dfs(flag,V[now][i]);
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	build(1,1);
	for(int i=1;i<=n;i++)color[i]=-1;
	int z=n,sum=0;
	while(z!=fath[z])
	{
		sum++;
		z=fath[z];
	}
	z=n;
	for(int i=1;i<=(sum-1)/2;i++)z=fath[z];
	color[z]=1;
	color[fath[z]]=0;
	dfs(1,z);
	dfs(0,fath[z]);
	if(ans[0]>ans[1])cout<<"Fennec";
	else cout<<"Snuke";
	return 0;
}