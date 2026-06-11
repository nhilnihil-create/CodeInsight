#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
int a[101010];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
		scanf("%d",&a[i]);
	for (int i=2;i<m;++i)
	if (a[i]%2==1)
	{
		if (a[1]%2==0)
			swap(a[1],a[i]);
		else if (a[m]%2==0)
			swap(a[i],a[m]);
		else
		{
			printf("Impossible\n");
			return 0;
		}
	}
	printf("%d",a[1]);
	for (int i=2;i<=m;++i)
		printf(" %d",a[i]);
	printf("\n");
	if (m==1)
	{
		if (a[1]==1)
		{
			printf("1\n1\n");
			return 0;
		}
		printf("2\n");
		printf("%d %d\n",1,a[1]-1);
		return 0;
	}
	if (a[m]==1 && m!=1) printf("%d\n",m-1);
	else printf("%d\n",m);
	
	if (m!=1) printf("%d",a[1]+1);
	else printf("%d",a[1]);
	for (int i=2;i<m;++i)
		printf(" %d",a[i]);
	if (m!=1 && a[m]!=1) printf(" %d\n",a[m]-1);
	
	return 0;
}