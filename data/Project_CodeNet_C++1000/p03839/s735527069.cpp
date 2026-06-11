#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 100010;

int n, k;

int v[MAXN];

lli sv[MAXN];
lli optPrefix[MAXN];
lli optSuffix[MAXN];

int main()
{
	scanf("%d %d",&n,&k);

	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&v[i]);

	for(int i = 1 ; i <= n ; i++)
	{
		sv[i] = sv[i - 1] + v[i];
		optPrefix[i] = optPrefix[i - 1] + max( v[i] , 0 );
	}

	for(int i = n ; i > 0 ; i--)
		optSuffix[i] = optSuffix[i + 1] + max( v[i] , 0 );

	lli ans = 0;

	for(int L = 1 ; L + k - 1 <= n ; L++)
	{
		int R = L + k - 1;

		lli curAns = optPrefix[ L - 1 ];
		curAns += optSuffix[ R + 1 ];
		curAns += max( 0LL , sv[R] - sv[L - 1] );

		ans = max( ans , curAns );
	}

	printf("%lld\n",ans);
}