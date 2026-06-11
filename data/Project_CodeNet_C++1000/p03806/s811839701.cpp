#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
const int MAXS = 500;
const int INF = 1000000010;

int n, x, y;

int a[MAXN];
int b[MAXN];
int c[MAXN];

int dp[MAXN][MAXS][MAXS];

int solve(int i, int sa, int sb)
{
	if( sa < 0 ) return INF;
	if( sb < 0 ) return INF;

	int& ans = dp[i][sa][sb];

	if( ans != -1 ) return ans;

	if( i == 0 )
	{
		if( sa == 0 && sb == 0 ) return ans = 0;
		return ans = INF;
	}

	ans = solve( i - 1 , sa - a[i] , sb - b[i] ) + c[i];
	ans = min( ans , solve( i - 1 , sa , sb ) );

	return ans;
}

int main()
{
	scanf("%d %d %d",&n,&x,&y);

	for(int i = 1 ; i <= n ; i++)
		scanf("%d %d %d",&a[i],&b[i],&c[i]);

	memset( dp , -1 , sizeof(dp) );

	int ans = INF;

	for(int k = 1 ; k <= 10 ; k++)
	{
		if( x*k >= MAXS || y*k >= MAXS ) continue;
		ans = min( ans , solve( n , x*k , y*k ));
	}

	if( ans == INF ) printf("-1\n");
	else printf("%d\n",ans);
}