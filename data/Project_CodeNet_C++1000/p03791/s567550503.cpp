#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define rep(i,a,b) for(register int i(a);i <= b;i++)
#define ll long long
using namespace std;
const ll mod = 1000000007;
int main()
{
	int n,x,k(0);ll ans(1);
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d",&x);++k;
		if(x < (k << 1) - 1) ans *= k,ans %= mod,--k;
	}
	while(k != 1) ans *= k,ans %= mod,--k;
	printf("%lld",ans);
	return 0;
}