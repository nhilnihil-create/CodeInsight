#include<bits/stdc++.h>
using namespace std;
int max1=0;
int main()
{
	int h,t;
	scanf("%d%d",&h,&t);
	int x;
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&x);
		max1=max(max1,x);
	}
	printf("%d\n",max(max1*2-1-h,0));
	return 0;
}