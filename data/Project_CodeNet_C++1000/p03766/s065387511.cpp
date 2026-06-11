#include<bits/stdc++.h>

#define int long long
#define ll long long
#define F first 
#define S second 
#define pb push_back
#define ld double

using namespace std ; 

const int MAXN = 1001 * 1001 , MOD =  1e9 + 7 ;

int dp[MAXN] ; 

int32_t main()
{
	ios::sync_with_stdio(0) ;
	int n ; 
	cin >> n ; 
	int ans = 0 ; 
	dp[0] = 1 ; 
	dp[1] = 1 ; 
	dp[2] = 1 ; 
	dp[3] = 2 ; 
	int s = 2 ; 
	for(int i = 4 ; i < MAXN ; i ++ ) 
	{
		dp[i] = dp[i-1] + s ;
		s += dp[i-2] ; 
		dp[i] %= MOD ; 
		s %= MOD ; 
	}
	ans ++ ; 

	for(int i = 0 ; i < n - 1 ; i ++ ) ans += dp[i] * (n-1) , ans %= MOD ; 
	
	for(int i = 0 ; i < n ; i ++ ) ans += dp[i] * (n-1) , ans %= MOD ; 

	for(int i = 0 ; i < n - 1 ; i ++ ) ans += dp[i] * (n-1) % MOD * (n-2) % MOD , ans %= MOD ;

	cout << ans << endl ; 	

}

