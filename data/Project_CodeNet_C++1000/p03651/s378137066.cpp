#include<bits/stdc++.h>
using namespace std;
int zd(int x,int y)
{
	if (x%y==0) return y;
	return zd(y,x%y);
}
int main()
{
	int n,k,x,y,max1=-1,z;
	scanf("%d%d%d",&n,&k,&x);
	z=x;
	max1=x;
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&y);
		z=zd(y,z);
		max1=max(max1,y);
	}
	if (k%z==0&&k<=max1) printf("POSSIBLE");
	else printf("IMPOSSIBLE");
	return 0;
}