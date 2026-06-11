#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[510][510];
int main()
{
	int h,w,H,W,i,j,ans=0;
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0)
	{
		printf("No\n");
		return 0;
	}
	for(i=h;i<=H;i+=h)
		for(j=w;j<=W;j+=w)
			a[i][j]=-w*h*1000+999;
	for(i=1;i<=H;i++)
		for(j=1;j<=W;j++)
		{
			if(!a[i][j])	a[i][j]=1000;
			ans+=a[i][j];
		}
	if(ans<0)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(i=1;i<=H;i++)
	{
		for(j=1;j<=W;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}