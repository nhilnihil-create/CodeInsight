#include <bits/stdc++.h>

#define mod 1000000007
#define maxn 2005
#define ll long long

using namespace std;

ll silnia[maxn*maxn];
ll dp[maxn][maxn];


void licz(int zosia)
{
	silnia[0]=1;
	for(int i=1; i<=zosia; ++i)
	{
		ll a=i;
		silnia[i]=(silnia[i-1]*a)%mod;
	}
}

ll qpow(ll zosia, int n)
{
	ll wynik=1;
	while(n!=0)
	{
		if(n%2==1)
			wynik=(wynik*zosia)%mod;
		zosia=(zosia*zosia)%mod;
		n/=2;
	}
	return wynik;
}

ll dwumian(int slonko, int misiu)
{
	ll c=(silnia[slonko-misiu]*silnia[misiu])%mod;
	//cout << c << endl;
	//cout << slonko << endl;
	//cout << silnia[slonko] << endl;
	return (silnia[slonko]*qpow(c,mod-2))%mod;
}

int main()
{
	//cout << dwumian(2,0) << endl;
	ll n,k;
	scanf("%lld%lld", &n, &k);
	
	if(k==1)
	{
		puts("1");
		return 0;
	}
	licz(n+n*k);
	//cout << dwumian(2,0) << endl;
	
	dp[0][0]=1;
	for(int i=0; i<=n; ++i)
	{
		for(int j=max(i,1); j<=n; ++j)
		{
			if(i!=0)
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			//cout << i+j*(k-1) << " " << k-2 << endl;
			//cout << dwumian(i+j*(k-1),k-2) << endl;
			if(j!=0)
				dp[i][j]=(dp[i][j]+(dwumian(i+j*(k-1)-1,k-2)*dp[i][j-1])%mod)%mod;
			//cout << i << " " << j << dp[i][j] << endl;
		}
	}
	printf("%lld", (dp[n][n]*silnia[n])%mod);
	return 0;
}

