#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 60;

int n, A, B;

int last[MAXN];

lli ans;

lli v[MAXN];
lli sv[MAXN];
lli ways[MAXN];
lli dp[MAXN][MAXN];

lli solve(int i, int j)
{
	lli& ans = dp[i][j];

	if( ans != -1 ) return ans;

	if( j == 0 ) return ans = 1;
	if( i == 0 ) return ans = 0;

	return ans = solve( i - 1 , j ) + solve( i - 1 , j - 1 );
}

int main()
{
	scanf("%d %d %d",&n,&A,&B);

	memset( dp , -1 , sizeof(dp) );

	for(int i = 1 ; i <= n ; i++)
		scanf("%lld",&v[i]);

	sort( v + 1 , v + n + 1 );

	for(int i = 1 ; i <= n ; i++)
	{
		if( v[i] != v[i - 1] ) last[i] = i;
		else last[i] = last[i - 1];
	}

	int first;

	for(int i = n ; i > 0 ; i--)
	{
		if( v[i] != v[i + 1] ) first = i;

		sv[i] = sv[i + 1] + v[i];
		ways[i] = solve( first - last[i] + 1 , first - i + 1 );
	}

	lli s = sv[n - A + 1];
	lli sz = A;

	lli ans = ways[n - A + 1];

	for(int i = A + 1 ; i <= B ; i++)
	{
		lli curS = sv[n - i + 1];

		if( s*i < sz*curS ) ans = ways[n - i + 1];
		if( s*i == sz*curS ) ans += ways[n - i + 1];
	}	

	double aux = s;
	aux /= sz;

	printf("%.10f\n",aux);
	printf("%lld\n",ans);
}