#include<bits/stdc++.h>
using namespace std;

int a[20200],b[20200];
int in[20200];
int ord[20200];

main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&in[i]);
		ord[in[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+ord[i];
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=n;i>=1;i--)
	{
		b[i]=b[i+1]+ord[i];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",b[i]);
	}
}