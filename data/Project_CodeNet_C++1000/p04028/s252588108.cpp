#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
 
const int Maxn = 5e3 + 10;
const ll Inf = 0;
const int Log = 20;
const ll Mod = 1e9 + 7;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll pw = b, j = 1; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}

ll p2[Maxn];
ll dp[2][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	p2[0] = 1;
	for(int i = 1; i < Maxn; i++) p2[i] = mul(p2[i - 1], 2);
	
	int n;
	cin >> n;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		int ii = i & 1;
		memset(dp[ii], 0, sizeof dp[ii]);
		for(int j = 0; j <= i; j ++){
			dp[ii][j] = 0;
			// write
			if(j) dp[ii][j] += (2LL * dp[ii ^ 1][j - 1]);
			// erase
			dp[ii][j] += dp[ii ^ 1][j + 1];
			if(j == 0) dp[ii][j] += dp[ii ^ 1][j];
			
			dp[ii][j] %= Mod;
		}
	}
	string s;
	cin >> s;
	int m = s.size();
	cout << mul(dp[n & 1][m], inv(p2[m])) << '\n';
	return 0;
}