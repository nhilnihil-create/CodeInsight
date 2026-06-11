#include<bits/stdc++.h>
using namespace std;

int n,m,a[210];

int main()
{
#ifdef h10
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int i,j;
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (n==1)
	{
		printf("%d\n",a[1]);
		if (a[1]==1)
			printf("1\n1\n");
		else
		{
			printf("2\n");
			printf("%d 1\n",a[1]-1);
		}
		return 0;
	}
	if (m&1)
	{
		for (i=1;i<=n;i++)
			if (a[i]&1) swap(a[1],a[i]);
		for (i=2;i<=n;i++)
			if (a[i]&1)
			{
				puts("Impossible");
				return 0;
			}
		for (i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
		printf("%d\n",n);
		printf("%d ",a[1]+1);
		for (i=2;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n]-1);
	}
	else
	{
		for (i=1;i<=n;i++)
		for (j=i+1;j<=n;j++)
			if (!(a[i]&1)&&(a[j]&1)) swap(a[i],a[j]);
		if (a[3]&1)
		{
			puts("Impossible");
			return 0;
		}
		swap(a[2],a[n]);
		for (i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
		printf("%d\n",n-(a[n]==1));
		printf("%d ",a[1]+1);
		for (i=2;i<n;i++)
			printf("%d ",a[i]);
		if (a[n]!=1) printf("%d",a[n]-1);
		puts("");
	}
}
