#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],res;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		res+=a[i]&1;
	}
	if(m==1)
	{
		printf("%d\n",a[1]);
		if(a[1]>1)
		{
			printf("2\n");
			printf("%d %d",a[1]-1,1);
		}
		else printf("1\n1");
		return 0;
	}
	if(res>=3)
	{
		printf("Impossible");
		return 0;
	}
	for(int i=1;i<=m;i++)
		if(a[i]&1)
			swap(a[1],a[i]);
	for(int i=m;i>=1;i--)
		if(a[i]&1)
			swap(a[i],a[m]);
	for(int i=1;i<=m;i++)
	{
		printf("%d ",a[i]);
		if(a[i]==1&&i==1)continue;
		b[++b[0]]=a[i];
		if(i==1)b[1]--;
	}
	++b[b[0]];
	printf("\n%d\n",b[0]);
	for(int i=1;i<=b[0];i++)
		printf("%d ",b[i]);
}