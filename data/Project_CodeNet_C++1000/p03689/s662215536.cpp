#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000000
int N,M,n,m;
int main()
{
	scanf("%d%d%d%d",&N,&M,&n,&m);
	if(N%n==0&&M%m==0)
	{
		printf("No\n");
		return 0;
	}
	int k=(INF-1)/(n*m-1);
	int l=k*(n*m-1)+1;
	l=-l;
	printf("Yes\n");
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			if(i%n==0&&j%m==0)
				printf("%d ",l);
			else printf("%d ",k);
		printf("\n");
	}
}