//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

typedef long long ll;

const int M = 2000 + 10, N = 6000000 + 10;
const int MOD = 1000000007;

ll dp[M][M], n, k, fac[N], inv[N];

ll mul(ll a, ll b){
	return a * b % MOD; 
}

ll add(ll a, ll b){
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

ll POW(ll x, ll t){
	ll res = 1;
	while (t){
		if (t & 1) res = mul(res, x);
		t >>= 1;
		x = mul(x, x);
	}
	return res;
}

ll ted(ll x, ll y){
	ll res = x * k + (y - x) * (k - 1);
	return res;
}

ll nCr(ll x, ll y){
	if (x < 0 || y < 0 || y > x) return 0;
	ll res = fac[x];
	res = mul(res, mul(inv[y], inv[x - y]));
	return res;
}

ll solve(ll ted, ll K){
	return nCr(K + ted - 1, ted - 1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	dp[0][0] = 1;
	//cout << POW(2, 4) << '\n';
	fac[0] = 1, inv[0] = 1;
	for (int i = 1; i < N; i++){
		fac[i] = mul(fac[i - 1], i);
		inv[i] = POW(fac[i], MOD - 2);
	}
	//cout << fac[4] << '\n';
	//cout << nCr(4, 2) << '\n';
	//cout << ted(0, 1) << '\n';
	if (k == 1) return cout << 1, 0;
	for (int i = 0; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (i == j && i == 0) continue;
			if (i == 0){
				if (j == 1) {dp[i][j] = 1;}
				else{
					ll res = solve(ted(i,j - 1) + 1, k - 2);
					dp[i][j] = mul(dp[i][j - 1], res);
 				}
			}
			else{
				if (i == j){
					dp[i][j] = dp[i - 1][j];
				}else{
					dp[i][j] = dp[i - 1][j];
					ll res = solve(ted(i, j - 1) + 1, k - 2);
					dp[i][j] = add(dp[i][j], mul(dp[i][j - 1], res));
				}
			}
			//cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}		
	}
	cout << mul(dp[n][n], fac[n]);
	
	return 0;
}