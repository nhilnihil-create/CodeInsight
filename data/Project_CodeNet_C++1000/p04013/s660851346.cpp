#include<bits/stdc++.h>
using namespace std;

const int nax = 55;

int main()
{
	using ll = long long;
	int n, a;
	cin >> n >> a;
	vector<int> x(n);
	for(int& i: x) cin >> i;
		
	vector<vector<ll>> dp(nax, vector<ll>(nax*nax));
	// dp[i][j] = #of ways to get sum 'j' by taking 'i' elements from the array
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = i; j >= 0; j--) {
			for(int k = 0; k < nax*nax; k++) {
				if(k + x[i] < nax*nax) {
					dp[j+1][k+x[i]] += dp[j][k];
				}
			}
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[i][i * a];
	}
	cout << ans << endl;
}
