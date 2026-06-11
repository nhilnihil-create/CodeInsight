// In the name of Allah
// #Isart

#include<bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double

using namespace std;

const int MAXN = 2e6 + 10, mod = 1e9 + 7;
ll dp[MAXN];

int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int n, ps = 0; cin >> n;
	dp[n] = n;
	dp[n - 1] = n * n % mod;
	
	for(int i = n + 1; i <= 2 * n; i ++) dp[i] = 1;
	for(int i = n + 1; i <= n + n - 1; i ++) ps += dp[i];
	for(int i = n - 2; i >= 1; i --){
		dp[i] = (dp[i + 1] + (n - 1) * (n - 1) % mod + ps % mod) % mod;
		ps = (ps - dp[i + n] + dp[i + 2] + mod) % mod;
	}	
	cout << dp[1] % mod << endl;

	return 0;	
}