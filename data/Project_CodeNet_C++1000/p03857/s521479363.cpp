#include <bits/stdc++.h>
using namespace std;
const int MAX_N=200005;
int n,K,L;
struct Union_Find
{
	int fa[MAX_N];
	void init()
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
	}
	int find(int x)
	{
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	void unite(int a,int b)
	{
		fa[find(a)]=find(b);
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
	void update()
	{
		for(int i=1;i<=n;i++)
		{
			find(i);
		}
	}
}rail,road;
map <pair<int,int>,int> connect;
int main()
{
	cin>>n>>K>>L;
	rail.init();
	road.init();
	while(K--)
	{
		int p,q;
		cin>>p>>q;
		road.unite(p,q);
	}
	while(L--)
	{
		int r,s;
		cin>>r>>s;
		rail.unite(r,s);
	}
	road.update();
	rail.update();
	for(int i=1;i<=n;i++)
	{
		connect[make_pair(road.fa[i],rail.fa[i])]++;
	//	cout<<"("<<road.fa[i]<<","<<rail.fa[i]<<")"<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<connect[make_pair(road.fa[i],rail.fa[i])]<<" ";
	}
	cout<<endl;
	return 0;
}
