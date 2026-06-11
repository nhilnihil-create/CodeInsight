#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll n,x,a,b,ans;
	scanf("%lld%lld",&n,&x);
	ans=n;
	a=x,b=n-x;
	while(1)
	{
		if(a<b)
			swap(a,b);
		ans+=a/b*b*2;
		a%=b;
		if(a==0)
			break;
	}
	ans-=b;
	printf("%lld",ans);
	return 0;
}
