#include <bits/stdc++.h>
using namespace std;
int n,dist1[100005],dist2[100005],resf,ress;
vector<int> son[100005];
void dfs1(int c,int f,int d)
{
	dist1[c]=d;
	for(int i=0;i<son[c].size();i++)
		if (son[c][i]!=f)
			dfs1(son[c][i],c,d+1);
}
void dfs2(int c,int f,int d)
{
	dist2[c]=d;
	for(int i=0;i<son[c].size();i++)
		if (son[c][i]!=f)
			dfs2(son[c][i],c,d+1);
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		son[a].push_back(b);
		son[b].push_back(a);	
	}
	dfs1(1,-1,0);
	dfs2(n,-1,0);
	for(int i=1;i<=n;i++)
		if (dist1[i]<=dist2[i])
			resf++;
		else
			ress++;
	if (resf>ress)
		cout<<"Fennec";
	else
		cout<<"Snuke";
	return 0;
} 