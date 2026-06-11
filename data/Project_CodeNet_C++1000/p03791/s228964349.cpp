#include<bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define ld long double
#define int long long

using namespace std ; 

const int MAXN = 101 * 1001 , MOD = 1e9 + 7 ; 

int a[MAXN] , b[MAXN] ; 

int fact[MAXN] ; 

int n ; 

bool check(int x)
{
	int cur = 1 ; 
	for(int i = 0 ; i < x ; i ++ ) 
	{
		if(a[i]<cur)
			return cout << i << ' ' << a[i] << ' ' <<cur << endl, 0 ; 
		b[i] = min(a[i],cur) ; 
		cur = b[i] + 2  ; 
	}	
	return 1 ;
}

int32_t main()
{
	ios::sync_with_stdio(0) ; cin.tie(0) ;
	fact[0] = 1 ;
	for(int i = 1 ; i < MAXN ; i ++ ) fact[i] = fact[i-1] * i % MOD ;
	cin >> n ;
	for(int i = 0 ; i < n ; i ++ ) cin >> a[i] ; 
	int ans = 1 , cur = 1 , cnt = 0  ;
	for(int i = 0 ; i < n ; i ++ ) 
	{
		cnt ++ ; 
		if(a[i]<cur)
		{
	//		cout << cnt << ' ' << i<< endl ; 
			ans *= cnt ; 
			cnt -- ;
			ans %= MOD ; 
		}
		else
		{
			cur += 2 ;
		//	cnt ++ ; 
		}
	}
	ans *= fact[cnt] ; 
	ans %= MOD ; 
	/*
	int l = 0 , r = n ; 
//	check(r) ; 
//	return 0 ; 
	while(r-l>1)
	{
		int mid = (r+l) / 2 ;
		if(check(mid))
			l = mid ;
		else
			r = mid ;
	}
	cout << check(n-1) << endl ; 
	cout << l << endl ;
	for(int i = 0 ; i < n ; i ++ )
		cout << fact[i+1] * fact[n-i] << endl ; 
	cout << fact[l+1] * fact[n-l] % MOD << endl ; ; 
	*/
	cout << ans << endl  ;
}