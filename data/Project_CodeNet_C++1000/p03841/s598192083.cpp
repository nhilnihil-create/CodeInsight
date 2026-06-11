#include<bits/stdc++.h>
using namespace std;

const int maxn=250010;

int n,a[maxn],a0[maxn];

int main()
{
#ifdef h10
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int i,j,x,p;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&x),a0[x]=a[x]=i;

	for (i=p=1;i<=n*n;i++)
		if (a0[i])
		{
			int val=a0[i];
			for (j=1;j<val;j++)
			{
				while (a[p]) p++;
				a[p]=val;
			}
			if (p>i) {puts("No"); return 0;}
		}

	for (i=p=n*n;i>=1;i--)
		if (a0[i])
		{
			int val=a0[i];
			for (j=val;j<n;j++)
			{
				while (a[p]) p--;
				a[p]=val;
			}
			if (p<i) {puts("No"); return 0;}
		}

	puts("Yes");
	for (i=1;i<=n*n;i++)
		printf("%d ",a[i]);
}
