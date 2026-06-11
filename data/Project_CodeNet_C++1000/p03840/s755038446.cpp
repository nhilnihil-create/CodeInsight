#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
LL ans,a,b,c,d,e,f,g;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g);
	ans+=b;
	if(a&&d&&e&&((a&1)+(d&1)+(e&1)>=2)) --a,--d,--e,ans+=3;
	ans+=2*(a/2+d/2+e/2);
	printf("%lld\n",ans);
	return 0;
}