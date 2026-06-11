#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,c[101010];
struct evol{int l,r,len;}a[303030];
bool cmp(evol u,evol v){ return u.len<v.len;}
void add(int x,int d)
{
	for(int i=x;i<=m;i+=(i&-i))
		c[i]+=d;
}
int query(int x)
{
	int res=0;
	for(int i=x;i;i-=(i&-i))
		res+=c[i];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r),a[i].len=a[i].r-a[i].l+1;
	sort(a+1,a+n+1,cmp);
	int p=1;
	for(int i=1;i<=m;i++)
	{
		while(p<=n&&a[p].len<i)
		{
			add(a[p].l,1);
			add(a[p].r+1,-1);
			p++;
		}
		int sum=0;
		for(int j=0;j<=m;j+=i)
			sum+=query(j);
		printf("%d\n",n-p+1+sum);
	}
	return 0;
}