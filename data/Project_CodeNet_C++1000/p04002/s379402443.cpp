#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
using namespace std;
long long ans[10];
map<pair<int,int>,int> g;
int main()
{
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	ans[0]=(long long)(h-2)*(w-2);
	while (n--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for (int i=x;i<x+3;i++)
			for (int j=y;j<y+3;j++)
				if (3<=i&&i<=h&&3<=j&&j<=w)
				{
					ans[g[make_pair(i,j)]]--;
					ans[++g[make_pair(i,j)]]++;
				}
	}
	for (int i=0;i<10;i++)
		printf("%lld\n",ans[i]);
	return 0;
}