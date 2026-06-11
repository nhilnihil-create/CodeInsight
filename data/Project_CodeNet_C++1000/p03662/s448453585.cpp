#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,f0,s0;
const int maxn=100005;
vector<int> v[maxn];
int f[maxn],s[maxn];
//bool f0[maxn],s0[maxn];
void bfs(int x,int a[])
{
	queue<int> q;
	q.push(x);
	a[x]=0;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++)
		{
			int d=v[t][i];
			if(a[d]>a[t]+1)
			{
			a[d]=a[t]+1;
			q.push(d);
		    } 
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	f[i]=s[i]=maxn;
	bfs(1,f);
	bfs(n,s);
	for(int i=1;i<=n;i++)
	{
		if(f[i]<=s[i])
		f0++;
		else s0++;
	}
	if(f0>s0)
	puts("Fennec");
	else puts("Snuke");
	return 0;
}