#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5007, mod = 1e9+7;

int n, dp[N][N], f[N], inv[N], pow2[N];
string s;

int binpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) (res*=a)%=mod, --b;
		else (a*=a)%=mod, b>>=1;
	}
	return res;
}

int inverse(int x){
	return binpow(x,mod-2);
}

void preset(){
	f[0] = inv[0] = pow2[0] = 1;
	for(int i=1;i<N;++i){
		f[i] = (f[i-1] * i)%mod;
		inv[i] = inverse(f[i]);
		pow2[i] = (pow2[i-1]*2)%mod;
	}
}

int catalan(int x){
	int f1 = inverse(x+1)*f[2*x]%mod, f2 = inv[x]*inv[x]%mod;
	return (f1*f2)%mod; 
}

signed main(){
	preset();

	cin >> n >> s;
	dp[0][0] = 1;
	
	int m = s.length();
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			(dp[i][j] += dp[i-1][max(j-1,0ll)]+2*dp[i-1][j+1])%=mod;
		}
	}
	cout << dp[n][m];
}