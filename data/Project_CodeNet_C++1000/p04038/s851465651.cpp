#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e6 + 123, mod = (int)1e9 + 7;

ll dp[2500][2500], f[N], rf[N], n, k;
void add(ll &a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
}
ll binpow(ll x,ll p){
	ll res = 1;
	while(p){
		if(p&1)
			res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}
ll C(int k,int n){
	return f[n] * rf[k] % mod * rf[n - k] % mod;
}
int main(){    
	f[0] = 1;
	for(int i = 1; i < N; i++)
		f[i] = 1ll * f[i - 1] * i % mod;
	rf[N - 1] = binpow(f[N - 1], mod - 2);
	for(int i = N - 2; i >= 0; i--)
		rf[i] = 1ll * rf[i + 1] * (i + 1) % mod;
	
	cin >> n >> k;

	if(k == 1)
		cout << 1, exit(0);
	
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			add(dp[i + 1][j], dp[i][j]);
			if(j < i)
            	add(dp[i][j + 1], 1ll *  dp[i][j] * C(k - 2, (n - j) * (k - 1) + n - i - 1) % mod );
		//	cerr << dp[i][j] << " ";
		}
		//cerr << endl;
	}

	cout << dp[n][n] * f[n] % mod << endl;
	return 0;
}
                     