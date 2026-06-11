#include <iostream>
#include <vector>
using namespace std;
#define sz 12000000
vector<int> v[100005];
int tree[sz],lc[sz],rc[sz],root[100005],cn;
void build(int node,int st,int en)
{
	if (st!=en)
	{
		lc[node]=++cn;
		rc[node]=++cn;
		int mid=(st+en)/2;
		build(lc[node],st,mid);
		build(rc[node],mid+1,en);
	}
}
void update(int node,int node2,int st,int en,int idx,int val)
{
	tree[node]=tree[node2];
	if (st==en)
	tree[node]+=val;
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		{
			lc[node]=++cn;
			rc[node]=rc[node2];
			update(lc[node],lc[node2],st,mid,idx,val);
		}
		else
		{
			rc[node]=++cn;
			lc[node]=lc[node2];
			update(rc[node],rc[node2],mid+1,en,idx,val);
		}
		tree[node]=tree[lc[node]]+tree[rc[node]];
	}
}
int query(int node,int st,int en,int l,int r)
{
	if (st>r || en<l || r<l)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return query(lc[node],st,mid,l,r)+query(rc[node],mid+1,en,l,r);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	root[0]=++cn;
	build(root[0],0,m);
	for (int i=0;i<n;i++)
	{
		int l,r,tmp=root[0];
		scanf("%d%d",&l,&r);
		root[0]=++cn;
		update(root[0],tmp,0,m,r,1);
		v[l-1].push_back(r);
	}
	for (int i=1;i<=m;i++)
	{
		root[i]=root[i-1];
		for (int r:v[i-1])
		{
			int tmp=root[i];
			root[i]=++cn;
			update(root[i],tmp,0,m,r,-1);
		}
	}
	for (int i=1;i<=m;i++)
	{
		int ans=n;
		for (int j=0;j<=m;j+=i)
		ans-=query(root[j],0,m,j,j+i-1);
		printf("%d\n",ans);
	}
}