#include<iostream>
#include<cstdio>
#define eps 4000
using namespace std;
int H,W,h,w,map[505][505];
long long sum;
int main()
{
	scanf("%d%d%d%d",&H,&W,&h,&w);
	for(int i=h;i<=H;i+=h)
		for(int j=w;j<=W;j+=w)
			map[i][j]=-eps*(h*w-1)-1,sum+=map[i][j];
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
		if(i%h||j%w)
		map[i][j]=eps,sum+=map[i][j];
	if(sum<=0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		printf("%d ",map[i][j]);
		puts("");
	}
	return 0;
}