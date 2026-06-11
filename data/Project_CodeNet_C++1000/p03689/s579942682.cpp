#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 500
#define MAXV 1000000000
using namespace std;
int M[MAXN+5][MAXN+5];
int main()
{
	int H,W,h,w;
	scanf("%d %d %d %d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0)
	{
		printf("No\n");
		return 0;
	}
	int k=(MAXV-1)/(w*h-1);
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			if(i%h==0&&j%w==0)
				M[i][j]=-k*(h*w-1)-1;
			else
				M[i][j]=k;
	printf("Yes\n");
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
			if(j==1)
				printf("%d",M[i][j]);
			else
				printf(" %d",M[i][j]);
		printf("\n");
	}
	return 0;
}