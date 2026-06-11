#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
map <pair<int,int>,int> cnt;
pair <int,int> p[202020];
int rt[202020];
int getr(int x)
{
	if(x==rt[x])
		return x;
	rt[x]=getr(rt[x]);
	return rt[x];
}
int main()
{
	int n,m1,m2,x,y;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++)
		rt[i]=i;
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&x,&y);
		rt[getr(x)]=getr(y);
	}
	for(int i=1;i<=n;i++)
		p[i].first=getr(i);
	for(int i=1;i<=n;i++)
		rt[i]=i;
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&x,&y);
		rt[getr(x)]=getr(y);
	}
	for(int i=1;i<=n;i++)
		p[i].second=getr(i);
	cnt.clear();
	for(int i=1;i<=n;i++)
		cnt[p[i]]++;
	for(int i=1;i<=n;i++)
		printf("%d ",cnt[p[i]]);
	return 0;
}