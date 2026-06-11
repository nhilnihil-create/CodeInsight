#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=505,INF=1e9;
int M[MAXN][MAXN];
int H,W,h,w;
int main()
{
	scanf("%d %d %d %d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	int k=(INF-1)/(h*w-1),f=0;
	f=k*(h*w-1)+1;
	f=-f;
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(i%h==0&&j%w==0)
				printf("%d ",f);
			else
				printf("%d ",k);
		}
		printf("\n");
	}
}