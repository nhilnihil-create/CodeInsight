#include<bits/stdc++.h>
using namespace std;
int H,W,h,w;
long long ans[600][600];

int main()
{
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(h==1&&w==1)
	{
		printf("No");
		return 0;
	}
	if(H%h==0&&W%w==0)
	{
		printf("No");
		return 0;
	}
	long long k=(long long)H*W/(h*w)+100;
	long long cnt=0;
	for(int i=1;i<=H;++i)
	{
		for(int j=1;j<=W;++j)
		{
			if(i%h==0&&j%w==0)
			{
				ans[i][j]=-k*(h*w-1)-1;
			}
			else
			{
				ans[i][j]=k;
			}
			cnt+=ans[i][j];
		}
	}
	if(cnt==0)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
		for(int i=1;i<=H;++i)
		{
			for(int j=1;j<=W;++j)
			{
				printf("%lld ",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}