#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int id[510];
int x[510];
int a[250010];
bool cmp(int a,int b)
{
	return x[a]<x[b];
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		id[i]=i;a[x[i]]=i;
	}
	sort(id+1,id+n+1,cmp);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		int u=id[i];
		for(int j=1;j<u;j++)
		{
			while(a[now])now++;
			if(now>x[u]){
				printf("No\n");
				return 0;
			}
			a[now]=u;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int u=id[i];
		for(int j=u;j<n;j++)
		{
			while(a[now])now++;
			if(now<x[u]){
				printf("No\n");
				return 0;
			}
			a[now]=u;
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n*n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}