#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=510;
struct data{int pos,w;}dt[N];
inline bool cmp(const data &a,const data &b){return a.pos<b.pos;}
int a[N*N];
int que[N],use[N];
int last[N],rk[N*N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&dt[i].pos);
		dt[i].w=i;a[dt[i].pos]=i;
	}
	sort(dt+1,dt+n+1,cmp);
	int sum=0,now=1;
	for(int i=1;i<=n;i++)
	{
		if(dt[i].pos-sum<dt[i].w)
		{
			printf("No\n");
			return 0;
		}
		for(int j=1;j<dt[i].w;j++)
		{
			while(a[now]) now++;
			a[now]=dt[i].w;
		}
		sum+=dt[i].w;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n-dt[i].w;j++)
	{
		while(a[now]) now++;
		a[now]=dt[i].w;
	}
	for(int i=1;i<=n*n;i++)
	{
		rk[i]=rk[last[a[i]]]+1;
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	if(rk[dt[i].pos]!=dt[i].w)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=n*n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}