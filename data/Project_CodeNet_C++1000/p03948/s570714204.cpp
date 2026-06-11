#include <bits/stdc++.h>
const int Maxn = 100010; 
int n, t, a[ Maxn ];
int main( )
{
	std::ios::sync_with_stdio( false );
	std::cin >> n >> t;
	int mx = 0, ans = 0, tot = 0;
	for( int i = 1; i <= n; ++i )
		std::cin >> a[ i ]; 
	for( int i = n; i; --i )
	{
		mx = std::max( a[ i ], mx );
		ans = std::max( ans, mx - a[ i ] ); 
	}
	mx = 0;
	for( int i = n; i; --i )
	{
		mx = std::max( a[ i ], mx );
		if( ans == mx - a[ i ] )
			tot++;
	}
	std::cout << tot;
	return 0;
}