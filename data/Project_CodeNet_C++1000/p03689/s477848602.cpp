#include<cstdio>
#include<algorithm>
#define MAX 1000000000
#define MAXN 506
using namespace std;
int n,m,a,b,s[MAXN][MAXN];
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(n%a==0&&m%b==0)
	{
		printf("No");
		return 0;
	}
	int k=MAX/(a*b);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i%a!=0||j%b!=0) s[i][j]=k;
			else s[i][j]=-(a*b-1)*k-1;
	printf("Yes");
	for(int i=1;i<=n;i++)
	{
		printf("\n");
		for(int j=1;j<=m;j++)
			printf("%d ",s[i][j]);
	}
}