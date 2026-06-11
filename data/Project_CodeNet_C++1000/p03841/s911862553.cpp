#include<iostream>
#include<cstdio>
#include<algorithm>
#define N (250000+1000)
using namespace std;

int n,ans[N],now;
struct Node{int num,pos;}a[N];
bool cmp(Node a,Node b){return a.pos<b.pos;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i].pos);
		a[i].num=i; ans[a[i].pos]=i;
	}
	sort(a+1,a+n+1,cmp);
	
	now=1;
	for (int i=1; i<=n; ++i)
	{
		for (int j=1; j<a[i].num; ++j)
		{
			while (ans[now]) now++;
			ans[now]=a[i].num;
		}
		if (now>a[i].pos){puts("No"); return 0;}
	}
	now=n*n;
	for (int i=n; i>=1; --i)
	{
		for (int j=1; j<=n-a[i].num; ++j)
		{
			while (ans[now]) now--;
			ans[now]=a[i].num;
		}
		if (now<a[i].pos){puts("No"); return 0;}
	}
	puts("Yes");
	for (int i=1; i<=n*n; ++i)
		printf("%d ",ans[i]);
}