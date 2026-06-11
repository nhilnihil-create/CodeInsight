#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510;
int n,m,x,y;
int a[N][N];
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	if(n%x==0&&m%y==0)
	{
		printf("No");
		return 0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=m;i++)
			a[k][i]=1000;
	for(int k=1;k<=n/x;k++)
		for(int i=1;i<=m/y;i++)
			a[k*x][i*y]=-(x*y*1000-1000+1);
	printf("Yes\n");
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++)
		{
			printf("%d ",a[k][i]);
		}
		printf("\n");
	}
	return 0;
}