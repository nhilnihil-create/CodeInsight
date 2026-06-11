#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define lowbit(x) (x&-x)

struct node { int l,r,len; }a[300010];

int c[100010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(node x,node y) { return x.len<y.len; }

inline void add(int x,int y) { for (;x<=m;x+=lowbit(x)) c[x]+=y; }

inline int query(int x)
{
	int res=0;
	for (;x;x-=lowbit(x)) res+=c[x];
	return res;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++)
	{
		a[i].l=rd();a[i].r=rd();
		a[i].len=a[i].r-a[i].l+1;
	}
	sort(a+1,a+n+1,cmp);
	int hh=1;
	for (int i=1;i<=m;i++)
	{
		for (;a[hh].len<i&&hh<=n;hh++) add(a[hh].l,1),add(a[hh].r+1,-1);
		int ans=n-hh+1;
		for (int j=0;j<=m;j+=i) ans+=query(j);
		printf("%d\n",ans);
	}
	return 0;
}