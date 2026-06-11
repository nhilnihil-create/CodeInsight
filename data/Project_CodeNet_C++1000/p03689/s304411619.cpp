#include<cstdio>
int n,m,h,w;
int main()
{
	scanf("%d%d%d%d",&n,&m,&h,&w);
	if(n%h)
	{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%d ",i%h?99999:(-100000*(h-1)));
			printf("\n");
		}
	}
	else if(m%w)
	{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%d ",j%w?99999:(-100000*(w-1)));
			printf("\n");
		}
	}
	else printf("No\n");
}