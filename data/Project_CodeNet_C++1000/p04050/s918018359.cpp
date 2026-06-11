#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxm=105;

int n,m,cntj,cur;
int a[maxm],b[maxm];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d",&a[i]);
		if (a[i]%2==1) cntj++;
	}
	if (m==1)
	{
		if (a[1]==1) 
		{
			printf("%d\n",a[1]);
			printf("1\n");
			printf("%d\n",a[1]);
		}
		else {
			printf("%d\n",a[1]);
			printf("2\n");
			printf("%d %d\n",a[1]-1,1);
		}
		return 0;
	}
	if (cntj>2) {
		printf("Impossible\n");
		return 0;
	}
	for (int i=2; i<=m; i++)
	{
		if (a[i]%2==1)
		{
			if (a[1]%2==1) swap(a[i],a[m]);
			else swap(a[1],a[i]);
		}
	}
	cur=0;
	if (a[1]>1) b[++cur]=a[1]-1;
	for (int i=2; i<m; i++)
		b[++cur]=a[i];
	b[++cur]=a[m]+1;
	printf("%d",a[1]);
	for (int i=2; i<=m; i++) printf(" %d",a[i]);
	printf("\n");
	printf("%d\n",cur);
	printf("%d",b[1]);
	for (int i=2; i<=cur; i++) printf(" %d",b[i]);
	printf("\n");
	
	return 0;
}