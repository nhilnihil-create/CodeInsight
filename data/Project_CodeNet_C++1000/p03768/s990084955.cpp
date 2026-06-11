#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,m,q,ans[N];
vector<int>v[N];
bool f[N]; int mindis[N];
int d[N],b[N],c[N];
inline void dfs(int color,int now,int far)
{
	if(far<=mindis[now])return;
	mindis[now]=far;
	if(!ans[now])ans[now]=color;
	for(int i=0;i<v[now].size();i++)
	{
		dfs(color,v[now][i],far-1);
	}
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)mindis[i]=-1;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	cin>>q;
	for(int i=0;i<q;i++)
		cin>>b[i]>>d[i]>>c[i];
	for(int i=q-1;i>=0;i--)
	{
		dfs(c[i],b[i],d[i]);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}
/*
7 7
1 2
1 3
1 4
4 5
5 6
5 7
2 3
2
6 1 1
1 2 2
************
14 10
1 4
5 7
7 11
4 10
14 7
14 3
6 14
8 11
5 13
8 3
8
8 6 2
9 7 85
6 9 3
6 7 5
10 3 1
12 9 4
9 6 6
8 2 3
*/