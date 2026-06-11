#include<bits/stdc++.h>
using namespace std ; 
#define int long long 
const int MAXN = 2000 + 10 , MOD = 1e9+7 ; 

int n , k , dp[MAXN][MAXN] , fact[MAXN*MAXN] ,inv[MAXN*MAXN];

int pw(int a , int b)
{
	if(!b)
		return 1 ; 
	int res = pw(a , b/2) ; 
	res*=res ;
	res%=MOD ; 
	if(b%2)
		res*=a ; 
	return res%MOD ;  
}

int C(int a , int b)
{
	if(b>a)	
		return 0 ; 
	return ( (fact[a] * inv[b])%MOD ) *inv[a-b] %MOD ; 
}


int32_t main()
{
	cin >> n >> k ; 
	if(k==1)
		return cout << 1 , 0 ; 
	fact[0]=1 ; 
	for(int i=1 ; i<MAXN*MAXN ; i++)
		fact[i] = fact[i-1]*i %MOD ; 
	for(int i=0 ; i<MAXN*MAXN ; i++)
		inv[i] = pw(fact[i] , MOD-2) ;
	dp[n][n] = 1 ; 
	for(int i=n ; i>=0 ; i--)
	{
		for(int j=n ; j>=i ; j--)
		{
			if(i) 
				dp[i-1][j]=(dp[i-1][j] + dp[i][j])%MOD;
			if(j>i) 
				dp[i][j-1]= (dp[i][j-1] + dp[i][j]*(C(i+j*(k-1)-1,k-2))%MOD)%MOD;
		}
	}
	cout << (dp[0][0]*fact[n])%MOD << endl ; 
}