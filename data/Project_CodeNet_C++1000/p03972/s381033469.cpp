#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int p[101010],q[101010];
int main()
{
	int h,w,st1=1,st2=1;
	long long ans=0;
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)
	{
		scanf("%d",&p[i]);
		ans+=p[i];
	}
	for(int i=1;i<=w;i++)
	{
		scanf("%d",&q[i]);
		ans+=q[i];
	}
	sort(p+1,p+1+h);
	sort(q+1,q+1+w);
	while(st1<=h&&st2<=w)
	{
		if(p[st1]<=q[st2])
		{
			ans+=(long long)p[st1]*(w-st2+1);
			st1++;
		}
		else
		{
			ans+=(long long)q[st2]*(h-st1+1);
			st2++;
		}
	}
	printf("%lld",ans);
	return 0;
}