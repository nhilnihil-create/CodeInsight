#include <bits/stdc++.h>
using namespace std;
int a[10005];
int b[105][105];
int main()
{
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x=1;
	int y=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i])
		{
			a[i]--;
			b[y][x]=i;
			if(y%2==0)
			{
				x--;
			}
			else
			{
				x++;
			}
			if(x>w)
			{
				x--;
				y++;
			}
			if(x<1)
			{
				x++;
				y++;
			}
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<w;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("%d\n",b[i][w]);
	}
	return 0;
}