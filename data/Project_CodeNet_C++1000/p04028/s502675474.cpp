#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char s[5010];
int sn;

ll dp[5010][5010];
const ll mod = int(1e9) + 7;

ll Pow(ll b, ll e){
	ll ret = 1;
	while(e){
		if(e&1) (ret*=b)%=mod;
		(b*=b)%=mod; e>>=1;
	}
	return ret;
}

int main()
{
	int n; scanf("%d%s", &n, s); sn=strlen(s);
	dp[0][0] = 1;
	for(int i=0; i<n; ++i){
		for(int j=0; j<=i; ++j){
			(dp[i+1][max(0, j-1)] += dp[i][j]) %= mod;
			(dp[i+1][j+1] += 2*dp[i][j]) %= mod;
		}
	}
	ll inv2 = Pow(2, mod-2);
	cout << dp[n][sn] * Pow(inv2, sn) % mod << endl;
	return 0;
}
