#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,c,d,n;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&n);
	a=8ll*a;b=4ll*b;c=2ll*c;
	if(a<=d||b<=d||c<=d)
	{
		a=min(a,min(b,c))/2ll;
		printf("%lld\n",a*n);
		return 0;
	}
	if(n%2==0)
	{
		printf("%lld\n",d*n/2ll);
		return 0;
	}
	else
	{
		ll ans=d*(n/2ll);
		//printf("%lld %lld %lld %lld\n",ans,a,b,c);
		ans+=min(a,min(b,c))/2;
		printf("%lld\n",ans);
	}
	return 0;
 } 