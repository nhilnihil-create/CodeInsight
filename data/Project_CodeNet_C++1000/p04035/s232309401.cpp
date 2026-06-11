#include<bits/stdc++.h>
using namespace std;
int n,l,a[100010];
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		if(a[i]+a[i+1]>=l)
		{
			printf("Possible\n");
			for(int j=1;j<i;j++)
				printf("%d\n",j);
			for(int j=n-1;j>=i;j--)
				printf("%d\n",j);
			return 0;
		}
	printf("Impossible");
}