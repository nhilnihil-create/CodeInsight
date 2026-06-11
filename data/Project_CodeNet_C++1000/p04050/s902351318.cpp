#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 110
int a[MAXN],b[MAXN],n,m,cnt,first,last;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2) cnt++;
	}
	if(cnt>2) printf("Impossible\n");
	else
	{
		bool first=1;
		for(int i=1;i<=m;i++)
			if(a[i]%2)
			{
				if(first) swap(a[i],a[1]),first=0;
				else swap(a[i],a[m]);
			}
		for(int i=1;i<=m;i++)
			printf("%d ",a[i]);
		printf("\n");
		if(cnt==2)
		{
			a[1]--,a[m]++;
			if(a[1]==0)
				printf("%d\n",m-1);
			else printf("%d\n",m);
			for(int i=1+(a[1]==0);i<=m;i++)
				printf("%d ",a[i]);
		}
		else if(cnt==1)
		{
			if(m==1&&a[1]!=1) printf("2\n%d 1\n",a[1]-1);
			else if(m==1&&a[1]==1) printf("1\n1\n");
			else
			{
				a[1]--,a[m]++;
				if(a[1]==0)
					printf("%d\n",m-1);
				else printf("%d\n",m);
				for(int i=1+(a[1]==0);i<=m;i++)
					printf("%d ",a[i]);
			}
		}
		else
		{
			if(m==1) printf("2\n%d 1\n",a[1]-1);
			else
			{
				a[1]--,a[m]++;
				if(a[1]==0)
					printf("%d\n",m-1);
				else printf("%d\n",m);
				for(int i=1+(a[1]==0);i<=m;i++)
					printf("%d ",a[i]);
			}
		}
	}
}