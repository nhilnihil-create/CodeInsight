#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005],per[20005];
int main()
{
	int n,k=20005;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&per[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=k;
		b[n-i+1]=k;
		k+=20005;
	}
	for(int i=1;i<=n;i++)
	{
		a[per[i]]-=20004-i+1;
		b[per[i]]-=20004-i+1;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d ",b[i]);
	}
}
