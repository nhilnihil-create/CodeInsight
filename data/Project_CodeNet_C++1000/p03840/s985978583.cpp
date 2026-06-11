#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,c,d,e,f,g;
long long ans;
int main()
{
	scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
	ans=a/2*4ll+b*2ll+d/2*4ll+e/2*4ll;
	if(a%2&&d%2&&e%2)
		ans+=6;
	else if(a%2+d%2+e%2==2)
	{
		if(a&&d&&e)
			ans+=2;
	}
	printf("%lld",ans/2);
	return 0;
}
