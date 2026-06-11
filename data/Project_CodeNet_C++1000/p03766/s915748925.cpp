#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000200;
const int MOD = 1e9 + 7;

using namespace std;

#define ll long long
ll dp[N];
ll pre[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ll n;
	cin >> n;

	dp[0] = 1;
	pre[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = pre[i - 1] + 1;

		if(i > 1){
			dp[i] -= dp[i - 2];
			if(dp[i] < 0){
				dp[i] += MOD;
			}
		} else if(i == 1){
			dp[i] -= 1;
		}

		pre[i] = (pre[i - 1] + dp[i]) % MOD;
	}



	ll ans = (dp[n - 1] + (n - 1) * (n - 1) + 1) % MOD;
	for(int i = 1; i < n; i++){
		ans = (ans + dp[i - 1] * (i + (i < n - 1))) % MOD;
	}


	for(int i = 1; i < n - 1; i++){
		ans = (ans + ((dp[i - 1] * (n - 1)) % MOD) * (n - 1)) % MOD;
	}
	cout << ans - (n == 1) << endl;

}
