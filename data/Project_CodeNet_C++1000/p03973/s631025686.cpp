#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,a,now=2;
	long long ans=0;
	scanf("%d%d",&n,&a);
	ans+=a-1;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a);
		if(a>now)
			ans+=(a-1)/now;
		else if(a==now)
			now++;
	}
	printf("%lld",ans);
	return 0;
}