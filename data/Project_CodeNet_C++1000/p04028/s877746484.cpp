#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX = 5e3+7, P = 1e9+7 , I2 = 5e8+4;

int dp[MAX][MAX];
char s[MAX];

int fpow(int b, int p)
{
	ll r = 1ll;
	while(p)
	{
		if(p&1)r *= b, r%=P;
		b = 1ll*b*b%P;
		p>>=1;
	}
	return r;
}

int main()
{
	dp[0][0] = 1;
	for(int i = 1; i<MAX; ++i)
		for(int j = 0; j<=i; ++j)
		{	
			if(j)dp[i][j] = (dp[i][j] + dp[i-1][j-1]%P)%P;
			else dp[i][j] = (dp[i][j] + dp[i-1][j]%P)%P; 
			
			if(j<i)dp[i][j] = (dp[i][j] + 2ll*dp[i-1][j+1]%P)%P;
		}	
	int n;scanf("%d", &n);
	scanf("%s", s);int l = strlen(s);
	//cerr << dp[n][l] << endl;
	printf("%d\n", dp[n][l]);
	
  	return 0;
}
