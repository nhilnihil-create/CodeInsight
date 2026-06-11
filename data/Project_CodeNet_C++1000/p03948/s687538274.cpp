#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int a[101010];
int main()
{
	int n,t,mi,p=0,c1,c2,ans=0;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mi=a[1];
	for(int i=2;i<=n;i++)
	{
		p=max(p,a[i]-mi);
		mi=min(mi,a[i]);
	}
	c1=c2=0;
	mi=a[1];
	c1=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-mi==p)
			c2++;
		if(a[i]==mi)
			c1++;
		else if(a[i]<mi)
		{
			mi=a[i];
			ans+=min(c1,c2);
			c1=1;
			c2=0;
		}
	}
	ans+=min(c1,c2);
	printf("%d",ans);
	return 0;
}