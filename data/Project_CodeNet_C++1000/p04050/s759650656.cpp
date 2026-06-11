#include<bits/stdc++.h>
using namespace std;
int a[2333333];
int main()
{
	int all,n,p=0,q=0;scanf("%d%d",&all,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]&1)
		{
			if (!p) p=i;
			else if (!q) q=i;
			else {printf("Impossible\n");return 0;}
		}
	}
	if ((n==1)&&(a[1]==1)) {printf("%d\n%d\n%d",1,1,1);return 0;}
	if (n==1) {printf("%d\n%d\n%d %d",a[1],2,a[1]-1,1);return 0;}
	if (p) swap(a[p],a[1]);
	if (q) swap(a[q],a[n]);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
	if (a[1]!=1)
	{
		printf("%d\n",n);
		printf("%d ",a[1]-1);
		for (int i=2;i<n;i++) printf("%d ",a[i]);
		printf("%d ",a[n]+1);
	}
	else
	{
		printf("%d\n",n-1);
		for (int i=2;i<n;i++) printf("%d ",a[i]);
		printf("%d ",a[n]+1);	
	}
}