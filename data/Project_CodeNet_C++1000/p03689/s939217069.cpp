#include<bits/stdc++.h>
using namespace std;
int k;
long long sum=0;
int main()
{
	int H,W,h,w;
	scanf("%d%d%d%d",&H,&W,&h,&w);
	k=int(1e9)/h/w;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
		{
			if(i%h==0&&j%w==0)sum-=(h*w-1)*k+1;
			else sum+=k;
		}
	if(sum<=0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(i%h==0&&j%w==0)printf("%d ",-(h*w-1)*k-1);
			else printf("%d ",k);
		}
		puts("");
	}
	return 0;
}